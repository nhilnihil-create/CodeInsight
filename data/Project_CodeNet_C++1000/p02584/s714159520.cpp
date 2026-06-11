//    ? WHY YOU OPEN THIS ?    //
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
 
#define PAIR    pair<int,int>
#define Vector  vector<int>
#define MAP     map<int,int>
#define pb      push_back
#define mk      make_pair
#define MOD     1e9+7 
#define all(a)  begin(a),end(a)
#define F       first
#define S       second
 
#define FOR(i, a, b)     for(int i = a; i < b; i++)
#define ROF(i, a, b)     for(int i = a; i>= b; i--)
#define check(c)       cout<<#c<<" : "<<c<<endl;
#define check2(a, b)    cout<<#a<<" : "<<a<<" | "<<#b<<" : "<<b<<endl;
#define check3(a, b, c)  cout<<#a<<" : "<<a<<" | "<<#b<<" : "<<b<<" | "<<#c<<" : "<<c<<endl;
#define SWIFT          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void testCase(){
    // int n; cin >> n;
    // int a[n]; FOR(i, 0, n) cin >> a[i];

	double x, d; int k; cin >> x >> k >> d;
	int ans, mn = min(k, (int)ceil(abs(x) / d));
	k -= mn;
	if(k == 0){
		ans = abs(abs(x) - mn * d);
	} else{
		if(k & 1){
			ans = abs((ceil(abs(x) / d) - 1) * d - abs(x));
		} else{
			ans = abs(ceil(abs(x) / d) * d - abs(x));
		}
	}
	cout << ans << endl;
}
 
signed main(){
    SWIFT;
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    // int t; cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}