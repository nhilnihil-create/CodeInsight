#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N;
  cin >> N;
  int a[N];
  rep(i, N)
    cin >> a[i];
  //入力終了

  // a[i]^a[i+1]^a[i+2] = 0と
  // a[i+1]^a[i+2]^a[i+3] = 0より  
  // a[i]^a[i+3] = 0が成り立ち
  // a[i] = a[i+3]

  // a[i] = xとするとa[]は
  // x, y, z, x, y, z, x, y, z, ....
  // と並び変えられる

  sort(a, a+N);

  // 0 0 0 0 0 , ....のとき
  if(a[0] == a[N-1] && a[0] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  
  // Nが3の倍数でないとダメ
  if(N%3 != 0){
    cout << "No" << endl;
    return 0;
  }

  // y = zのとき
  // x y y x y y x y y , ....
  // x^y^y = 0 より，x=0
  // 0 y y 0 y y 0 y y , ....のとき
  // 最初のN/3項が0で，残りがすべてy
  if(a[N/3-1] == 0 && a[N/3] == a[N-1]){
    cout << "Yes" << endl;
    return 0;
  }

  // y != zのとき
  // x y z x y z , ....
  if(a[0] == a[N/3-1] && a[N/3] == a[N*2/3-1] && a[N*2/3] == a[N-1]){
    if((a[0]^a[N/3]^a[N*2/3]) == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
  }

  
  cout << "No" << endl;
    
  return 0;
}
