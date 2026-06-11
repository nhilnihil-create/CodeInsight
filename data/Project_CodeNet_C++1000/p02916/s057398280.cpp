#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forN(i, n) for(int i = 0; i <n ; ++i)
#define endl "\n"
#define noob (main)
typedef long long ll;
using namespace  std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int N = 2e5 +5 ;
int n,A[25],B[25],C[25];

int noob(){
    fastIO;
    cin>>n;
    for(int i = 1 ; i<=n; i++){
        cin>>A[i];
    }
    for(int i = 1 ; i<=n; i++){
        cin>>B[i];
    }
    for(int i = 1 ; i<n; i++){
        cin>>C[i];
    }
    int ans = 0;
    for(int i = 1 ; i<=n;i++){
        ans+=B[A[i]];
        if(i>1){
            if(A[i]-A[i-1]==1){
                ans+=C[A[i-1]];
            }
        }
    }
    cout<<ans;
}

