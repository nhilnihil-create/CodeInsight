#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=998244353;
using namespace std;


int main(){
int N;
cin>>N;
vector<long long >v(N);

rep(i,N){
    cin>>v[i];
    
}
long long ans=1;
if(v[0]!=0)ans=0;
sort(v.begin(),v.end());






int mp[100001]={};
for(int i=1;i<N;i++){
    if(v[i]==0 || v[i]>=N){
        ans=0;
        break;
    }

    if(v[i]>1){
    ans*=mp[v[i]-1];
    if(ans>=mod)ans%=mod;
    }
mp[v[i]]++;

}

cout<<ans<<endl;
 return 0;
}
/*

*/
