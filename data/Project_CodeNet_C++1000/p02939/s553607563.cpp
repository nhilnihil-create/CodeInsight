#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <cstdlib>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 2e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int BASE = 31337;

char s[N];
int n, sol = 0, lst = 0;

int main(){
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0;i < n;){
		int cur = 0;
		for(;i < n && (cur == lst || cur == 0);i++)
			cur = BASE * cur + s[i];
		if(lst == cur && i == n)
			break;
		lst = cur;	
		sol++;
	}
	printf("%d\n", sol);
	return 0;
}
