#include <bits/stdc++.h>
#define pb push_back
#define Int int64_t
using namespace std;

int64_t N;
int64_t K;
int main()
{
    cin>>N>>K;
    vector<Int> A(N),B(N);
    for(auto &x:A) cin>>x;
    for(auto &itr:B) cin>>itr;
    
    sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());
    
    Int low=0,high=1e12;
    Int answer=high;
    while(low<=high){
        Int mid=(low+high)>>1LL;
        Int sum=0;
        for(int i=0;i<N;++i) sum+=max((Int)0,A[i]-mid/B[i]);
        if(sum<=K){
            high=mid-1;
            answer=mid;
        }
        else low=mid+1;
    }

    cout<<answer<<"\n";
}