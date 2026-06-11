#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define Int int64_t
using namespace std;
#define BITS 62
const Int M=(Int)(1e9+7);

inline Int mmul(Int a,Int b){if(a>=M)a=a%M;if(b>=M)b=b%M;if(a*b>=M)return(a*b)%M;return(a*b);}
inline Int madd(Int a, Int b){if(a>=M)a=a%M;if(b>=M)b=b%M;if(a+b>=M)return(a+b)%M;return(a+b);}
Int N;

int main()
{
   cin>>N;
   vector<Int> A(N);
   for(auto &x:A) cin>>x;
   Int ans=0;
   
    for(int i=0;i<BITS;++i){
        Int nums0=0,nums1=0;
        for(int j=0;j<N;++j){
            if(A[j]%2==0) ++nums0;
            else ++nums1;
            A[j]>>=1LL;
        }
        Int init=mmul(nums0,nums1);
        ans=madd(ans,mmul((1LL<<i),init));
        
    }
    cout<<ans<<"\n";
}