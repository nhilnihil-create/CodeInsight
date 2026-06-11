#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  long long N,K;
  //a = 3.0;
  //b = 2.0;
  long long ans1=0,ans2=0;
  cin >> N >> K;
  int ia;
  int mod = pow(10,9)+7;
  vector<int> via(0);//初期の配列のサイズを0にセット
  for(int i=0;i<N;i++){
    cin >> ia;   
    via.push_back(ia);
  }
  for(int i=1;i<N;i++){
    for(int j=0;j<N-i;j++){
      if(via[j]>via[j+i]){
        ans1++;
      }
    }
  }
  for(int i=0;i<N;i++){
    via.push_back(via[i]);
  }
  for(int i=1;i<N*2;i++){
    for(int j=0;j<N*2-i;j++){
      if(via[j]>via[j+i]){
        ans2++;
      }
    }
  }
  long long ans=0;
  if(K%2==0){
    ans = (((ans1%mod)*K)%mod + ((((ans2-(ans1*2)%mod)%mod * (K/2)%mod)%mod)*(K-1))%mod)%mod;
  }else{
    ans = (((ans1%mod)*K)%mod + ((((ans2-(ans1*2)%mod)%mod * ((K-1)/2)%mod)%mod)*(K))%mod)%mod;
  }


  cout << ans << endl;
  //cout << "test" << endl;
}