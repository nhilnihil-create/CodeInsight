#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 9223372036854775807;
const ll mininf = -9223372036854775807;
const ll nax = 0;
int n, k;

int main(){
	IOS
	int a, b, c;
	cin >> a >> b >> c;
	int cnt=0;
	if(a==b) cnt++;
	if(c==a) cnt++;
	if(b==c) cnt++;
	if(cnt==1){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}