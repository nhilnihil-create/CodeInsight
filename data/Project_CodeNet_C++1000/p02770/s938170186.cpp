#include<bits/stdc++.h>
using namespace std;
 
using lint=long long;

int main()
{
   cin.tie(0);
   ios::sync_with_stdio(false);

   int K,Q; cin>>K>>Q;
   vector<int> d(K);
   for(int i=0;i<K;i++) cin>>d[i];

   while(Q--){
      int N,X,M; cin>>N>>X>>M;
      vector<int> D=d;
      for(int i=0;i<K;i++) D[i]=(D[i]%M==0? M:D[i]%M);
      lint fst=X,lst=X;
      lst+=accumulate(D.begin(),D.end(),0LL)*((N-1)/K);
      lst+=accumulate(D.begin(),D.begin()+(N-1)%K,0LL);
      cout<<(N-1)-(lst/M-fst/M)<<endl;
   }
   return 0;
}
