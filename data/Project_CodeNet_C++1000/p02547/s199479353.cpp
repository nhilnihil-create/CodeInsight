#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N;
	cin >> N;
	int cnt = 0, ans = 0;
	rep(i,N)
	{
		int d1,d2;
		cin >> d1 >> d2;
		if (d1 == d2) cnt++;
		else cnt = 0;
		ans = max(ans,cnt);
	}
	if (ans >= 3) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}