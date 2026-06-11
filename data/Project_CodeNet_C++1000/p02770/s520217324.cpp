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
      for(int i=0;i<K;i++) D[i]%=M;

      lint fst=X,lst=X;
      lint sumD=0;
      for(int i=0;i<K;i++) sumD+=D[i];
      for(int i=0;i<(N-1)%K;i++) lst+=D[i];
      lst+=(lint)sumD*((N-1)/K);

      int cnt_gt=lst/M-fst/M;
      int cnt_eq=0;
      for(int i=0;i<K;i++) if(i+1<N){
         if(D[i]!=0) continue;
         cnt_eq+=((N-1)-(i+1))/K+1;
      }
      int cnt_lt=(N-1)-cnt_gt-cnt_eq;
      cout<<cnt_lt<<endl;
   }
   return 0;
}
