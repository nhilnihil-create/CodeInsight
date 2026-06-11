#include <iostream>
#include <vector>
#include <complex>

using namespace std;

typedef complex<int> P;

P conv[4] = {
	P(-1, 0),
	P(0, -1),
	P(1, 0),
	P(0, 1),
};

int main() {
	int N;
	while ( cin >> N, N ) {
		vector<P> v;
		v.push_back( P(0, 0) );
		int mx = 0, my = 0, Mx = 0, My = 0;
		for (int i = 0; i < N-1; ++i) {
			int n, d; cin >> n >> d;
			P p = v[n] + conv[d];
			mx = min(mx, p.real());
			my = min(my, p.imag());
			Mx = max(Mx, p.real());
			My = max(My, p.imag());
			v.push_back(p);
		}
		int w = Mx - mx + 1;
		int h = My - my + 1;
		cout << w << " " << h << endl;
	}
}