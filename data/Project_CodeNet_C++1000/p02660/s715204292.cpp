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
	map<ll,ll> mp;
	ll n;
	cin>>n;
	for(int i=2;(long long)i*i<=n;i++){
		if(n%i==0){
			int count=0;
			while(n%i==0){
				n/=i;
				count++;
			}
			mp[i]=count;
		}

	}
	if(n>1){
		mp[n]=1;
	}
	int count=0;
	for(auto it: mp){
		int i=1;
		while(i<=it.second){
			count++;
			it.second-=i;
			i++;
		}
	}
	cout<<count;
}