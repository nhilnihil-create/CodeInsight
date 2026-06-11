#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define mod 1000000007LL
#define FOR(i,m,n) for(int i = (m); i < (n); i++)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())
 
 
typedef long long ll;
typedef vector<int> vi; 
typedef pair<int,int> ii;


ll pow(ll a, ll b){
    int ans = 1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}


const int N=1e5;


void run(){
	
	int a, b; cin>>a>>b;
	
	
	if(a%2 != b%2) cout<<"IMPOSSIBLE";
	else cout<<(a+b)/2;
	
	
	
}


int main(){
	
	fastio;
	
	int tt=1; 
	//cin>>tt;
	
	while(tt--){
		run();
	}
	
	return 0;
}
