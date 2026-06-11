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
vector<int> ve(3006, 0);
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
	int i = 0;
	long long a;
	long long sum=100;
	cin>>a;
	while(sum<a){
		if(a-sum*1/100<=sum){
			i++;
			break;
		}
		else{
			sum=sum+(sum)*1/100;
			i++;

		}
	}
	cout << i;

}