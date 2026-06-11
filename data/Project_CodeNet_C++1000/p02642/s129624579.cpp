#include <bits/stdc++.h>

/*                    ॐ Shree ॐ                     */
/* ॐ ॐ ॐ
ॐ भूर् भुवः स्वः
तत् सवितुर्वरेण्यं
भर्गो देवस्य धीमहि
धियो यो नः प्रचोदयात्
*/
using namespace std;
typedef long long ll;
vector<int> cunt(1000000,0);
bool getdiv(int n){
	if(n!=1 && cunt[1]>0||cunt[n]>1){
		return true;
	}
	int sum=0;
	for(int i=2;(long long)i*i<=n;i++){
		if(n%i==0){
			if(cunt[i]>0||cunt[n/i]>0){
				return true;
			}
		}

	}
	return false;
}
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
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		cunt[v[i]]++;
	}
	int coun=0;
	for(int i=0;i<n;i++){
		if(getdiv(v[i])) coun++;
	}
	cout<<n-coun;
}