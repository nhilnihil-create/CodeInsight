#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int a, b;
const double oe = 0.08;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> a >> b;
	b *= 10;
	for(int i = b; i/10 == b/10; i++){
		if(floor((double)i * oe) == a){
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	cout.flush();
	return 0;
}