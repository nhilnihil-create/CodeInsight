#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <iterator>
#include <vector>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '
 
const int MAXN = 2 * 1e5 + 5;
char s[MAXN];

int largest(int a, int b){
	return (a<b)?b:a;
}


int main() {
	int a = 0, b = 0, m = 0;
	cin >> a >> b >> m;
	vector<int> r(a);
	vector<int> mi(b);
	for(int i = 0; i < a; ++i){
		cin >> r[i];
	}
	for(int i = 0; i < b; ++i){
		cin >> mi[i];
	}
	int minf = *min_element(r.begin(), r.end());
	int minm = *min_element(mi.begin(), mi.end());
	int ans = minf + minm;
	int x = 0, y = 0, c = 0;
	for(int i = 0; i < m; ++i){
		cin >> x >> y >> c;
		x--,y--;
		ans = min(ans,r[x]+mi[y]-c);
	}
	cout << ans << endl;


	

	

    return 0;
}