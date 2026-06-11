#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
	ll a;
	cin >> a;
	string b;
	cin >> b;
	int k = int(b[0]-'0')*100 + int(b[2]-'0')*10 + int(b[3]-'0');
	cout << a*k/100 << endl;
	return 0;
}