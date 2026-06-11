#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
 int N;
 cin>>N;
 vector<int64_t>A(N);
 for(int i=0;i<N;i++){
     cin>>A[i];
 }
 int64_t ans=0;
 for(int i=0;i<60;i++){
   int64_t cnt1=0,cnt0=0;
   for(int j=0;j<N;j++){if(A[j]>>i&1){cnt1++;} }
   cnt0=N-cnt1;
   int64_t t=cnt1*cnt0%1000000007;
   for(int j=0;j<i;j++){
    t=t*2%1000000007;
   }
   ans+=t;
   ans%=1000000007;
 }
 cout<<ans<<endl;
 return 0;
}
