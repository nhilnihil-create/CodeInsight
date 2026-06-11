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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int64_t n, a, b; cin >> n >> a >> b;

	if ((b-a)%2==0) {
		cout << (b-a)/2 << "\n";
	} else {
		int64_t ans = b-1;	
		pMin(ans,n-a);
		{
			int64_t toLeft = a; // time
			pMin(ans, toLeft + (b-toLeft)/2);
		} 
		{
			int64_t toRight =n-b+1;
			pMin(ans, toRight + (n-a-toRight)/2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}


