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
const int N = 1000 + 5;
ll h , n ,A[N] , B[N],DP[N][10004];

ll calc(int idx , int health){
    if(health<=0)return 0;
    if(idx == n ){
        if(health>0){
            return INF;
        }
        return 0;
    }
    if(DP[idx][health]!=-1)return DP[idx][health];
    ll take = calc(idx , health-A[idx]) + B[idx];
    ll dont = calc(idx+1 , health);
    return DP[idx][health] = min(take,dont);
}

int main(){
    fastIO;
    cin>>h>>n;
    for(int i = 0 ; i<n ; i++){
        cin>>A[i]>>B[i];
    }
    memset(DP,-1,sizeof DP);
    cout<<calc(0,h);
}
