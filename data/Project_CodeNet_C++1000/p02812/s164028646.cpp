#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 29;
using ll = long long int;
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; ++i)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int c = 0;
	const string find_word("ABC");
	string::size_type pos = s.find(find_word);
	while (pos != string::npos) {
		++c;
		pos = s.find(find_word, pos + find_word.length());
	}

	cout << c << endl;
}