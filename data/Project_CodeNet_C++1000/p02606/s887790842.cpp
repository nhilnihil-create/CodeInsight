#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int l, r, d;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> l >> r >> d;
	int ans = 0;
	for(int i = l; i<=r; i++)
		if(i%d == 0) ans++;

	cout << ans << endl;

	cout.flush();
	return 0;
}