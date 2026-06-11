#include <bits/stdc++.h>

#define pp push_back
#define pf push_front
#define mp make_pair
#define fs first
#define sc second
#define sf scanf

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

const int N = (int) 1e5;
const int INF = (int) 1e9 + 7;

int main(int argc, char *argv[])
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int a, b, c, d;
	sf("%d %d %d %d", &a, &b, &c, &d);
	int x = (int) ceil((float)c / b);
	int y = (int) ceil((float)a / d);
	puts(x <= y ? "Yes" : "No");

	return 0;
}
