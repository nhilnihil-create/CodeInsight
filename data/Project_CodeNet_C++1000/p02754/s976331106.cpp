#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	ll N,A,B;
	cin >> N >> A >> B;
	ll s = A+B;
	ll ans = N / s * A;
	ans += min((N%s),A);
	cout << ans << endl;
	return 0;
}