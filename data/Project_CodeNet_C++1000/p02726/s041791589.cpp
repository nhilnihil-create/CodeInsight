#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
#define pii pair<int,int>
#define pll pair<long long,long long>
#define usi unordered_set<int>
#define usl unordered_set<long long>
#define umii unordered_map<int,int>
#define umsi unordered_map<string,int>
#define umll unordered_map<long long,long long>
#define fi first
#define sec second
#define pub push_back
#define pob pop_back
#define B begin
#define E end
#define mp make_pair
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define vll vector<pll>
#define deb(x) cout<<#x<<": "<<x<<"\n"
#define endl '\n'
#define PIE 3.141592653
#define MOD 1000000007
#define f(i,a,b,c) for(ll i=a;i<=b;i+=c)
#define frev(i,n,b,c)  for(ll i=n;i>=b;i-=c)
const ll inf = 1000000000000000000;
using namespace std;
 
//            < = = = = =    GCD     = = = = = >
 
ll gcd(ll a,ll b)
{
	if(a<b)	gcd(b,a);
	if(b==0)	return a;
	return gcd(b,a%b);
}
 
//            < = = = = =    LCM     = = = = = >
 
ll lcm(ll a,ll b) 
{ 
	ll x=(a/gcd(a,b))*b; 
	return x;
}
 
//            < = = = = =    power  x^n     = = = = = >
 
ll power(ll x , ll n , ll m=inf){
	if(x==0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	ll ans;
	if(n%2==0){
		ll smallAns = power(x,n/2,m);
		ans = (smallAns*smallAns)%m;		
	} else {
		ll smallAns = power(x,n-1,m);
		ans = x;
		ans = (ans*smallAns)%m;
	}
	// for negative values also
	return (ans+m)%m;
	
}
 
//            < = = = = =    CHECK FOR PRIME     = = = = = >
 
bool isprime(int n){
   if(n==2){
        return true;
    }
    else if(n%2==0){
        return false;
    }
    else{
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
}
 
//            < = = = = =    SOLVE    = = = = = >
 
// bool cmp(pll x, pll y){
//     ll dx = min(2*(x.first),x.second)-min(x.first,x.second);
//     ll dy = min(2*(y.first),y.second)-min(y.first,y.second);
//     return dx>dy;
// }
 
// void rec(int n){
//     if(){
//         return;
//     }
    
//     return;
// }
 
int solve() {fastio
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>v[n];
    map<int,int>m;
    f(i,0,n-2,1){
        m[i]=0;
        v[i].push_back(i+1);
        v[i+1].push_back(i);
    }
    v[x-1].push_back(y-1);
    v[y-1].push_back(x-1);
    m[n-1]=0;
    f(i,0,n-1,1){
        queue<int>q;
        bool visited[n];
        f(k,0,n-1,1)visited[k]=false;
        q.push(i);
        visited[i]=true;
        int shortDis[n];
        shortDis[i]=0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for (auto j : v[top]) {
                if(visited[j]==false){
                    visited[j]=true;
                    q.push(j);
                    shortDis[j]=shortDis[top]+1;
                }
            }
        }
        
        for (auto j : shortDis) {
            if(j!=0){
                m[j]++;
            }
        }
    }
    for (auto i : m) {
        if(i.first!=0){
            cout<<(i.second)/2<<endl;
        }
    }
    return 0;
}

//            < = = = = =    MAIN     = = = = = >
 
int main() {fastio
    
 	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}