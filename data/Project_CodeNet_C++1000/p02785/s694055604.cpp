#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,K,ans = 0;
  cin >> N >> K;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  for(int i=0; i<N; i++){
   if(i<K){
     continue;
   }
    else{
      ans += vec[i];
    }
  }
cout << ans << endl;
}
      