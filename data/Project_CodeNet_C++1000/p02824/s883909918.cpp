#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
ll dp0[366][366],dp1[366][366];
int main()
{
    int N,V,P;
    ll M;
    cin >> N >> M >> V >> P;
    vector<ll>A(N);
    rep(i,N)cin >> A[i];
    sort(A.begin(),A.end());
    int l=-1,r=N;
    while(r-l>1){
        int mid=(l+r)/2;
        int res=V-mid-1;
        bool ok =true;
        for(int i=mid+1;i<N-P+1;i++){
            ok&=(A[mid]+M>=A[i]);
        }
        if(!ok){l=mid;continue;}
        ll sum = (res-P+1)*M;
        for(int i=mid+1;i<N-P+1;i++){
            sum-=min(M,A[mid]+M-A[i]);
        }
        if(sum>0){l=mid;}
        else{r=mid;}
    }
    cout << N-l-1 << endl;
    return 0;
}
