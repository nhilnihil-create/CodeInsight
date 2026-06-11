#include <iostream>
#include <vector>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  int m1 = 0, m2 = 0;
  for(int i = 0; i < N; i++){
    if(m1 <= a[i]){
      m2 = m1;
      m1 = a[i];
    }
    else if(m1 > a[i] && m2 < a[i]) m2 = a[i];
  }
  for(int i = 0; i < N; i++){
    if(a[i] == m1) cout << m2 << endl;
    else cout << m1 << endl;
  }
}
