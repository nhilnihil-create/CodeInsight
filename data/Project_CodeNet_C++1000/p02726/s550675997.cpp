// Gaurav Nuti
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii > vii;
typedef vector<pll > vll;
#define pb push_back
#define mp make_pair 
#define ar array
#define mod 1000000007
#define F first
#define S second
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define For(i, a, b) for(__typeof (a) i=a; i<=b; i++)
#define inp_arr(a,n) for(__typeof (n) i=0; i<n; ++i) {cin>>a[i];}
#define debug_arr(a,n) {{for(__typeof (n) i=0; i<n; ++i) {cout<<a[i]<<" ";}cout<<"\n";}}
#define INF 1e9 

ll power(ll x, ll y) 
{ 
    ll res = 1;   
    while (y > 0) { 
        if (y & 1) 
            res = (res*x)%mod; 
        y = y>>1;
        x = (x*x)%mod; 
    } 
    return res%mod; 
}

ll power_without_mod(ll x, ll y) 
{ 
    ll res = 1;   
    while (y > 0) { 
        if (y & 1) 
            res = (res*x); 
        y = y>>1;
        x = (x*x); 
    } 
    return res; 
}

bool comparep(pair<ll, ll> i1, pair<ll, ll> i2){
	return (i1.S < i2.S);
} 

ll modInverse(ll a)
{
    return power(a , mod - 2);
}

vector<vector<ll>> graph;
vector<bool> visited;
vector<ll> dist;
map<ll,ll> mymap;
ll max_dist = 1;

void bfs(int u1){
    visited[u1] = 1;
    dist[u1] = 1;
    mymap[1] = u1;
    queue<ll> q;
    q.push({u1});
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto i=graph[u].begin();i!=graph[u].end();i++){
            if(!visited[*i]){
                dist[*i] = dist[u] + 1;
                visited[*i] = 1;
                max_dist = max(dist[*i],max_dist);
                mymap[dist[*i]] = *i;
                q.push({*i});
            }
        }
    }
}

// int next_lunlun(ll n){
//     vector<int> digits;
//     while(n){
//         digits.pb(n%10);
//         n /= 10;
//     }
//     // reverse(digits.begin(),digits.end());
//     ll num_digits = digits.size(); 
//     int count_9 = 0;
//     for(int i: digits)
//         if(i == 9)
//             count_9++;
//     if(count_9 == num_digits)
//         return ;
//     for(int i=0;i<(num_digits-1);i++){
//         if(digits)
//     }
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif  
	
    ll t;
    // cin>>t;
    t = 1;
    for(ll z=0;z<t;z++){
        ll n, x, y;
        cin>>n>>x>>y;
        x--;y--;
        // cout<<x<<" "<<y<<"\n";
        vector<ll> dist(n,0);
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                ll new_dist = 1 + abs(x-i) + abs(j-y);
                // cout<<i<<" "<<j<<" "<<j-i<<" "<<new_dist<<"\n";
                dist[min(j-i,new_dist)]+=1;
            }
        }
        for(int i=1;i<n;i++){
            cout<<dist[i]<<"\n";
        }
    }
}