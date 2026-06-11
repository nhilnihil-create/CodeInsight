#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    //vector<pair<int, int>> v(n);
  	vector<int> a(n), b(n);
  	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];  
  	//for(auto& x : v) cin >> x.first >> x.second;
    sort(a.begin(), a.end());
  	sort(b.begin(), b.end());
    if(n & 1) {
        ans = b[n/2] - a[n/2] + 1;
    }
    else {
        //cout << v[n/2].second << ' ' << v[n/2].first << ' ' << v[n/2 - 1].second << ' ' << v[n/2 - 1].first << endl;
        ans = b[n/2] - a[n/2] + 1 + b[n/2 - 1] - a[n/2 - 1];
    }
    cout << ans;
    return 0;
}
