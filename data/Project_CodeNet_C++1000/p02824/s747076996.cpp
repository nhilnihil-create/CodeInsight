#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000000

int main(){
   ll N,M,V,P;
   cin>>N>>M>>V>>P;
   vector<ll> A(N);
   for(int i=0;i<N;i++){
     cin>>A.at(i);
   }
   sort(A.begin(),A.end());

   ll base=A.at(N-P);
   vector<ll> sum(N+1,0);
   for(int i=0;i<N;i++){
     sum.at(i+1)=sum.at(i)+A.at(i);
   }

   int ans=P;
   for(ll i=0;i<N-P;i++){
     ll x=A.at(i)+M;
     if(x<base){
       continue;
     }
     if(V<=P){
       ans++;
       continue;
     }
     if(M*(V-P-i)<=(x-base)+x*(N-P-i-1)-(sum.at(N-P)-sum.at(i+1))){
       ans++;
     }
   }
   cout<<ans<<endl;
}
