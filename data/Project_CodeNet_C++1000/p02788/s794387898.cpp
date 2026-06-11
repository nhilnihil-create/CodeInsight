#include<bits/stdc++.h>
#define fastio     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(x)   cerr<<#x<<": "<<x<<endl;
#define all(x)     (x).begin() , (x).end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define endl       '\n'
#define MAX        1000000
typedef long long int ll;
using namespace std;


const ll mod = 1e9+7;
const double eps = 1e-9;


vector<int>cost,value;
int h , n;
int dp[10001][1002]; 

int recur(int ind,int w) {
    if(ind==0&&w>0)return 1e9;
    else if(ind>=0&&w<=0)return 0;

    if(dp[w][ind]!=-1)return dp[w][ind];

    int first=recur(ind,w-cost[ind-1])+value[ind-1];
    int second=recur(ind-1,w);
    return dp[w][ind]=min(first,second);
}

void show(int a,int b){
    for(int i=0;i<=a;i++) {
        for(int j=0;j<=b;++j) {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void solve(){
    cin>>h>>n;
    cost.resize(n+1);
    value.resize(n+1);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) {
        cin>>cost[i]>>value[i];
    }
    cout<<recur(n,h)<<endl;
}

ll res[200005];

void sec() {
    ll n,d,a;
    cin>>n>>d>>a;
    vector<pair<ll,ll>>arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    sort(all(arr));
    int end=0;
    ll ans=0;
    for(int start=0;start<n;start++) {
        while(end<n&&arr[end].first<=arr[start].first+2*d){
            end++;
        }
        ll req=max((arr[start].second-res[start]*a+a-1)/a,0LL); 
        ans+=req;
        res[start]+=req;
        res[end]-=req;
        res[start+1]+=res[start];
    }
    cout<<ans;
}



int main(){
    fastio
    int test=1;
    while(test--)
        sec();
    return 0;
}
