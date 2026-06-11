#include<bits/stdc++.h>
#include<string>
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
ll k , n ,A[N];


int main(){
    fastIO;
    cin>>n>>k;
    for(int i = 0 ; i<n ; i++){
        cin>>A[i];
    }
    sort(A,A+n);
    ll ans = 0;
    for(int i = n-1 ; i>=0 ; i--){
        if(k>0){
            k--;
            continue;
        }
        ans+=A[i];
    }
    cout<<ans;

}
