#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define pb push_back 
#define pob pop_back
#define mp make_pair

void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	int ans =1e9;
	ans = min((a+b),min(a+c,min(b+a,min(b+c,min(c+a,c+b)))));
	cout<<ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1; 
    while(t--){
      solve();
    }
    return 0;
}