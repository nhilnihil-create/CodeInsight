#include<iostream>
#include<complex>
#include<queue>

using namespace std;

int main() {
	int n;
	queue<complex<float> > q;
	const complex<float> end(100, 0);
	const complex<float> c3(3, 0),c2(2,0);
	const complex<float> a60(0.5, sqrt(3) / 2.0);
	q.emplace(0, 0);
	q.emplace(100, 0);
	cin >> n;
	complex<float> a, b;
	for (int i = 0;i < n;i++) {
		a = q.front();
		q.pop();
		q.push(a);
		while (a != end) {
			b = q.front();
			q.pop();
			q.push(a + (b - a) /c3);
			q.push(a + (b - a) / c3 + (b - a) * a60 / c3);
			q.push(a + (b - a) * c2 / c3);
			q.push(b);
			a = b;
		}
	}
	while (!q.empty()) {
		cout << q.front().real() << " " << q.front().imag() << endl;
		q.pop();
	}
}
