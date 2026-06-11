#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	long a,b,c,d;
	long max = LONG_MIN;
	cin >> a >> b >> c >> d;
	long A, B, C, D;
	A = a * c;
	B = a * d;
	C = b * c;
	D = b * d;
	priority_queue<long> pq;
	pq.push(A);
	pq.push(B);
	pq.push(C);
	pq.push(D);
	cout << pq.top() << endl;
	return (0);
}