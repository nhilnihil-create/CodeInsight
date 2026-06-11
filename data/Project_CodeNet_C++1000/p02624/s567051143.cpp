#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define unmap  	unordered_map<int,int>
#define	unset	unordered_set<int>
#define maxpq  	priority_queue<int>
#define minpq  	priority_queue<int, vector<int>, greater<int>>
#define sort(v)  sort(v.begin(),v.end());
#define sortd(v) sort(v.begin(),v.end(),greater<int>());
#define pb 		push_back
#define ll 		long long
#define ff 		first
#define ss 		second//typedef second ss;
#define foton(i,n) for(int i=0;i<n;i++)
#define	faton(i,a,n)	for(int i=a;i<=n;i++)
#define mod 	1000000007
#define endl "\n"
using namespace std;
int prime[10000001];
void solve(){
   ll n;cin>>n;

   for(ll i=1;i<=n;i++){
           for(ll j=i;j<=n;j+=i){
                prime[j]++;
            } 
        
   }

    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ans += i*prime[i];
    }
    cout<<ans<<endl;
}

int main(){
    fastio;
    solve();
    return 0;
}
