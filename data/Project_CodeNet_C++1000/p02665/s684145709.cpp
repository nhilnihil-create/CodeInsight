#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i < n + 1; ++i){
	cin >> a[i];
    }
    vector<ll> s(n + 1);
    s[n] = a[n];
    for(int i = n - 1; i >= 0; --i){
	s[i] = s[i + 1] + a[i];
    }
    vector<ll> ans(n + 1);
    ans[0] = 1;
    ll x = 1;
    for(int i = 1; i < n + 1; ++i){
	if(ans[i - 1] - a[i - 1] > 0){
	    ans[i] = min(2 * (ans[i - 1] - a[i - 1]), s[i]);
	    x += ans[i];
	}else{
	    cout << "-1" << endl;
	    return 0;
	}
    }
    if(a[0] > 1 || (a[0] == 1 && n != 0) || a[n] != ans[n]){
	cout << "-1" << endl;
    }else{
	cout << x << endl;
    }
    
    return 0;
}
