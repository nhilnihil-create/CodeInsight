#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
int main(){
	int a,b;
	cin >> a >> b ;
	if(a <= 2*b)
	cout << 0 << endl;
	else cout << a - 2*b << endl;
}
