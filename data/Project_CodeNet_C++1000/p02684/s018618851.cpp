#include <bits/stdc++.h>

/*                    ॐ Shree ॐ                     */
/* ॐ ॐ ॐ
ॐ भूर् भुवः स्वः
तत् सवितुर्वरेण्यं
भर्गो देवस्य धीमहि
धियो यो नः प्रचोदयात्
*/

using namespace std;
typedef long long int ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
// online submission
#endif
	ll n;
	ll k;
	cin >> n >> k;
	vector<ll> vv(n+10);
	for (ll i = 1; i <= n; i++) {
		cin >> vv[i];
	}
	vector<bool>visited(1000000,false);
	vector<ll> v;
	ll i = 1;
	v.push_back(1);
	visited[i]=true;
	while (true) {
		if(visited[vv[i]]==true){
			break;
		}
		v.push_back(vv[i]);
		i = vv[i];
		visited[i]=true;
		
	}
	ll first=0;
	for(ll j=0;j<(ll)v.size();j++){
		if(v[j]==vv[i]){
			first=j;
			break;
		}
	}

	if(k<(ll)v.size()){
		cout<<v[k];
	}

	else{
		
		ll last=(ll)v.size()-1;
		k-=first;
		ll r=(k%(last-first+1));
		cout<<v[first+r];
	}


}