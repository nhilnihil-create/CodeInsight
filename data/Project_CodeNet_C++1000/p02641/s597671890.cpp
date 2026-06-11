#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define first F
#define second S
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int x, n; cin>>x>>n;
	map<int, int> m;
	for(int i=0; i<n; i++){
		int y; cin>>y;
		m[y]++;
	}
	int dif=1e5;
	for(int i=0; i<102; i++){
		if(m[i]==0){
			dif=min(dif, abs(x-i));
		}
	}
	if(m[x-dif] == 0)cout<<x-dif<<endl;
	else cout<<x+dif<<endl;
}
