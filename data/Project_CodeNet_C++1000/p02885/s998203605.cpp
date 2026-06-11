#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 

template <class T>
void printArray(vector<T> arr) {for (T a: arr) cout << a << " ";cout << '\n';}
void printVerdict(bool verdict) {cout << (verdict ? "YES": "NO") << '\n';}
void printDecimal(double d) {printf("%.9f\n", d);}
bool inrange(int val, int start, int end) {return val >=start && val <= end;}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a,b; cin >> a >> b;
	cout << max(a-2*b, 0) << '\n';
}

