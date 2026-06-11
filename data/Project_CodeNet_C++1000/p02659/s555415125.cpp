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
	ll a;
	cin>>a;
	string b;
	cin>>b;
	int m=(b[0]-'0')*100+(b[2]-'0')*10+(b[3]-'0');
	cout<<(a*m)/100;
}
