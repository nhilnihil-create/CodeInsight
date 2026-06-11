#pragma gcc optimize(2)
#include <iostream>
#include <queue>
#include <map>
#include <bitset>
#include <string>
#include <set>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <ctime>
//#include <unordered_map>
#include <stack>
#include <cstdlib>
#include <numeric>
#include <cassert>
#include <complex>
using namespace std;
#define maxn 200007
#define maxm 400007
#define maxq 1000007
#define maxl 1234
#define modn 998244353
#define scan(a) scanf("%d",&a)
#define scanl(a) scanf("%lld",&a)
#define scanl2(a,b) scanf("%lld%lld",&a,&b)
#define scans(a) scanf("%s",a)
#define scans2(a,b) scanf("%s%s",a,b)
#define scand(a) scanf("%lf",&a)
#define scan2(a,b) scanf("%d%d",&a,&b)
#define scand2(a,b) scanf("%lf%lf",&a,&b)
#define scan3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scan4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define scan5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define print(a) printf("%d\n",a);
#define printl(a) printf("%lld\n",a);
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i=a;i>= b;i--)
#define fscan(a) fscanf(stream,"%d", &a);
#define mp      make_pair	
#define pb      push_back
#define eb      emplace_back
#define mm(a,b) memset(a,b,sizeof a)
#define log2(n) (double)(log(n) / log(2.0))
#define _crt_disable_perfcrit_locks
#define bll __int128
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef map <char, int> mci;
typedef map <char, char> mcc;
typedef pair <char, int> pci;
typedef complex<double> cd;
typedef vector<complex<double> > vcd;

const double eps = 1e-8;
const double pi = 2 * acos(0.0);

int cc, bb; char ch; inline int F() {
	while (ch = getchar(), (ch < 48 || ch> 57) && ch != '-'); ch == '-' ? cc = bb = 0 : (cc = ch - '0', bb = 1);
	while (ch = getchar(), ch > 47 && ch < 58)cc = (cc << 1) + (cc << 3) + (ch ^ 48); return bb ? cc : -cc;
}
void write(int x) {
	int y = 10, len = 1;
	while (y <= x) { y *= 10; len++; }
	while (len--) { y /= 10; putchar(x / y + 48); x %= y; }
}
int n;
string s;
int has1 = 0;
int sum = 0;
int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//FILE* stream = fopen("L:/1.in", "rb+");
	cin >> n >> s;
	int t = n - 2;
	for (int i = 0; i < n - 1; i++) {
		s[i] = abs(s[i] - s[i + 1]);
		if (s[i] & 1 && (t | i) == t)//如果s[i]是奇数且c(n-2,i)为奇数
			sum++;
		if (s[i] == 1)has1 = 1;
	}
	if (sum & 1)
		cout << 1 << endl;
	else if (has1)
		cout << 0 << endl;
	else {
		sum = 0;
		for (int i = 0; i < n - 1; i++) {//全是0和2
			s[i] >>= 1;
			if (s[i] & 1 && (t | i) == t)//如果s[i]是奇数且c(n-2,i)为奇数
				sum++;
		}
		if (sum & 1)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}