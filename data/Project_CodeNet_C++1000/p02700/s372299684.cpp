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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int i=0;
	while(a&&c){
		if(i%2){
			a=max(0,a-d);
		}
		else{
			c=max(0,c-b);
		}
		i++;
	}
	if(a==0){
		cout<<"No";
	}
	else{
		cout<<"Yes";
	}
}