    #include <bits/stdc++.h>
    using namespace std;
     
    #define fi first
    #define se second
    #define sz(v) (int)((v).size())
    #define pb push_back
     
    typedef long long ll;
     
    int main()
    {
    	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     
    	int n, k; cin >> n >> k;
    	vector<double> p(n);
    	for (int i=0; i<n; i++) cin >> p[i];
    	double exp = 0;
    	for (int i=0; i<k; i++) exp += (p[i]+1)/2;
    	double ans = exp;
    	for (int i = k; i < n; i++) {
    		exp += (p[i]+1)/2;
    		exp -= (p[i-k]+1)/2;
    		ans = max(ans, exp);
    	}
    	cout << fixed << setprecision(6) << ans << "\n";
    }