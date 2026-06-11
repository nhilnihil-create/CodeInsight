#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef struct _PT {
	double x;
	double y;
} PT;

void printp(PT p) {
	cout << fixed << setprecision(5) << p.x << " " << p.y << endl;
}

void kock(int n, PT p1, PT p2) {
	if (n == 0)
		return;

	// p1, p2 から s, t, u を計算
	PT u, v, p, q, r;
	u.x = p2.x - p1.x; u.y = p2.y - p1.y;
	v.x = p1.y - p2.y; v.y = p2.x - p1.x;
	p.x = p1.x + u.x / 3; p.y = p1.y + u.y / 3;
	q.x = p1.x + u.x / 2 + sqrt(3) * v.x / 6;
	q.y = p1.y + u.y / 2 + sqrt(3) * v.y / 6;
	r.x = p1.x + u.x * 2 / 3; r.y = p1.y + u.y * 2 / 3;

	kock(n-1, p1, p);
	printp(p);
	kock(n-1, p, q);
	printp(q);
	kock(n-1, q, r);
	printp(r);
	kock(n-1, r, p2);
}

int main() {
	int n;
	PT p1, p2;
	p1.x = 0.0; p1.y = 0.0;
	p2.x = 100.0; p2.y = 0.0;
	cin >> n;
	printp(p1);
	kock(n, p1, p2);
	printp(p2);

	return 0;
}