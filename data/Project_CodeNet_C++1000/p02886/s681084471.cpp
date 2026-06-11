#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N;
   cin>>N;
   int sum=0;
   vector<int> D(N);
   rep(i,N){
       cin>>D[i];
       sum+=D[i];
   }
   int ans=0;
   rep(i,N-1){
       ans+=D[i]*(sum-D[i]);
       sum-=D[i];
   }
    cout<<ans<<endl;
}
