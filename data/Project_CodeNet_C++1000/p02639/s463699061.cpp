#include <bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x = 0; x < n; ++x)
#define vector_loop(x,n) for(int i = 0; x < n; i++)
#define vii(n) vector<int> a(n)
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    vector<int> a(5);
	int index = 0;
	for (int i = 0; i < 5; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 5; ++i)
	{
		if (a[i] == 0)
		{
			index = i;
			break;
		}
	}
	cout << index + 1;


}