#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int n, a[N], mk[N], f, gc;
void work(int x)
{
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i == 0)
		{
			if(mk[i])
			{
				f = 1;
				return;
			}
			mk[i] = 1;
			while(x % i == 0) x /= i;
		}
	}
	if(x != 1)
	{
		if(mk[x])
		{
			f = 1;
			return;
		}
		mk[x] = 1;
	}
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
    	cin >> a[i];
    	work(a[i]);
	}
	gc = __gcd(a[1], a[2]);
	for(int i = 3; i <= n; i++) gc = __gcd(gc, a[i]);
	if(gc != 1) cout << "not coprime" << endl;
	else if(f) cout << "setwise coprime" << endl;
	else cout << "pairwise coprime" << endl;
	return 0;
}
