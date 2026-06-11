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
	vector<int> count(101,0);
	int n,k,d,t;
	cin>>n>>k;
	while(k--){
		cin>>d;
		while(d--){
			cin>>t;
			count[t]++;
		}
	}
	t=0;
	for(int i=1;i<=n;i++){
		if(count[i]==0){
			t++;
		}
	}
	cout<<t;


}