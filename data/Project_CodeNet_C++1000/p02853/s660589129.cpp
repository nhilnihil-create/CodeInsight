#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef vector < int > vi;

int x, y;

int main(){
	scanf("%d%d", &x, &y);
	printf("%d\n", (max(0, 4 - x) + max(0, 4 - y)) * (int)1e5 + (x + y == 2) * (int)4e5);
	return 0;
}
