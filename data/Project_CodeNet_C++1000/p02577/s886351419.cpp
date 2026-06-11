#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	string n;
	cin >> n;
	ll sum = 0;
	for(int i=0;n[i];i++){
		sum += n[i] - '0';
	}
	if(sum%9 == 0)
	cout << "Yes";
	else
	cout << "No";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

