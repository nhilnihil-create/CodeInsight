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
	int x,n;
	cin>>x>>n;
	// int arr[x]={0};
	map<int,int> m;
	FOR(i,n){
		int v;
		cin>>v;
		m[v]++;
	}
	// cout<<arr[4];
	int MINI = 1e9;
	int ans;
	for(int i=-300;i<=300;i++){
		if(!m[i]){
			if(MINI>abs(x-i)){
				MINI = abs(x-i);
				ans = i;
			}
	    }
    }
    cout<<ans;
}

int main(){

    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1; 
    // cin>>t;
    while(t--){
      solve();
    }
    return 0;
}