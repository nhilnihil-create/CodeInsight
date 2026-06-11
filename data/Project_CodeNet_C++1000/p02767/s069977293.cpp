#include <bits/stdc++.h>

using namespace std;

int main(){
  int N,ans=10000000;
  cin >> N;
  vector<int> ary(N);

  for(int i = 0 ; i < N ; i++){
    cin >> ary[i];
  }
  sort(ary.begin(),ary.end());
  for(int i = 1 ; i <= ary[N-1] ;i ++){
    int P = i;
    int tmp = 0;
    for(int j = 0 ; j < N ; j++){
            tmp += (ary[j] - P) * (ary[j] - P);
    }
    if(ans > tmp){
      //cout << "tmp is refresh " << tmp << " when p is " << P << endl;
      ans = tmp;
    }else{
      break; 
    }
  }

    cout << ans << endl;
}
