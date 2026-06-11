#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

int A[200005], B[200005];
ll A_acc[200005], B_acc[200005];
int n, m, k;

int main(){
    AC
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        cin>>A[i];
        A_acc[i] = A_acc[i-1] + (ll)A[i];
    }
    for(int i=1; i<=m; i++){
        cin>>B[i];
        B_acc[i] = B_acc[i-1] + (ll)B[i];
    }

    int aid = n;
    while(A_acc[aid]>k)
        aid--;
    
    int ans = aid;
    int bid = 1;
    while(1){
        if(A_acc[aid]+B_acc[bid]<=k){
            ans = max(ans, aid+bid);
            bid++;
        }
        else
            aid--;
        if(aid<0 || bid>m)
            break;
    }
    cout<<ans<<endl;

}