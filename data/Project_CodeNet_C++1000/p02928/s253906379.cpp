#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
int main(){
  	long long N,K,a=0,b=0;
  	cin>>N>>K;
  	vector<long long> A(N);
  	unordered_map<long long,long long> mp;
  	for(long long i=0;i<N;i++){
      	cin>>A.at(i);
    }
  	for(long long i=0;i<N;i++){
      	mp[A.at(i)]++;
      	for(long long j=A.at(i)+1;j<=2000;j++){
          	if(mp[j]>0){
              	a+=mp[j];
            }
        }
    }
  	for(long long i=0;i<N;i++){
      	for(long long j=A.at(i)+1;j<=2000;j++){
          	if(mp[j]>0){
              	b+=mp[j];
            }
        }
    }
    long long ans;
    if(K%2==0){
      	ans=a*K%MOD+(K/2)*(K-1)%MOD*b%MOD;
      	ans%=MOD;
    }
  	else{
      	ans=a*K%MOD+(K*((K-1)/2)%MOD)*b%MOD;
      	ans%=MOD;
    }
    cout<<ans<<endl;
}