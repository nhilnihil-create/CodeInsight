#include <iostream>
#include <climits>
#include <numeric>
#include <cassert>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <array>
#include <memory>

#define IN(a,b) (a.find(b) != a.end())
#define p(a,b) make_pair(a,b)
#define readVec(a) for (int __i = 0; __i<(int)a.size();__i++){cin>>a[__i];}

// jimjam

template<typename T>
void pMin(T &a, T b) {if (b<a){a=b;}}
template<typename T>
void pMax(T &a, T b) {if (b>a){a=b;}}
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c);
template<typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A,B>& c) {std::cout << "(" << c.first << ", " << c.second << ")";return os;}
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c) {
	if (c.size() == 0) {os << "{}"; return os;}
	os << "{" << c[0];
	for (int64_t i = 1; i < (int)c.size(); i++) {os <<", "<<c[i];}
	os << "}";
	return os;
}

using namespace std;

bool grid[6][6];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, w, k ;cin >> h >> w >> k;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			char ch ; cin >> ch;
			grid[x][y] = (ch=='#');
		}
	}

	int ans=0;
	for (int i=0; i < (1<<(h+w)); i++) {
		int curr=0;
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				int t1 = (i & (1<<x));
				int t2 = (i & (1<<w+y));
				if (grid[x][y] && ((i & (1<<x))==0) && ((i & (1<<w+y)) == 0)) {
					curr++;
				}
			}
		}
		if (curr==k) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}


