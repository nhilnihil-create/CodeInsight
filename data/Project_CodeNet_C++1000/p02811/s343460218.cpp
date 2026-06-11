#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 

template <class T>
void printArray(vector<T> arr) {for (T a: arr) cout << a << " ";cout << '\n';}
void printVerdict(bool verdict) {cout << (verdict ? "Yes": "No") << '\n';}
void printDecimal(double d) {printf("%.9f\n", d);}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k,x; cin >> k >> x;
	bool verdict = k*500 >= x;
	printVerdict(verdict);
}

