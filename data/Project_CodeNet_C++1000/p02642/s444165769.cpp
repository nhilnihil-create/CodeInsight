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
	vector<int> count(1000000,0);
	int a;
	int mx=0,mn=200001;
	for(int i=0;i<n;i++){
		cin>>a;
		count[a]++;
		mx=max(mx,a);
		mn=min(mn,a);
	}
	vector<int> visited(mx+1,false);
	int cont=0;
	for(int i=mn;i<=mx;i++){
		if(count[i]==1 && visited[i]==false){
			cont++;
		}
		if(count[i]>=1){
			for(int j=i;j<=mx;j+=i){
				visited[j]=true;
			}
		}

	}
	cout<<cont;
}