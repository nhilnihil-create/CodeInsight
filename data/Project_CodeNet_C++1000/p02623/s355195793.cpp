#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define forN(i, n) for(int i = 0; i <n ; ++i)
#define endl "\n"
typedef long long ll;
using namespace  std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
ll n , m , k,A[N],B[N] , PA[N] , PB[N];

int main() {
    fastIO;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    for(int i = 0 ; i<n ; i++){
        PA[i+1] = PA[i] + A[i];
    }
    for(int i = 0 ; i<m ; i++){
        PB[i+1] = PB[i] + B[i];
    }
    int ans =0 ;
    for(int i = 0 ; i<=n ; i++){
        if(k-PA[i]<0)break;
        ll val = k - PA[i];
        int l = 0 , r = m+1;
        while(l+1<r){
            int mid = (l+r)/2;
            if(PB[mid]<=val){
                l = mid ;
            }
            else{
                r = mid ;
            }
        }
        ans = max(ans,l+i);
    }
    cout<<ans;

}

