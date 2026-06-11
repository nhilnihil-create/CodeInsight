#include<bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<int> vi;

const int MAXN = 102;
int n;
double x[MAXN], y[MAXN], s1, s2, s3, s00;

int main(){
//	freopen(".in", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++)
		cin >> x[i];
	for(int i=0; i<n; i++)
		cin >> y[i];

	for(int i=0; i<n; i++){
		double d = abs(x[i] - y[i]);
		s1 += d;
		s2 += d*d;
		s3 += d*d*d;
		s00 = max(s00, d);
	}

	cout << setprecision(6) << fixed;

	cout << s1 << '\n' << pow(s2, 1.0/2) << '\n' << pow(s3, 1.0/3) << '\n' << s00 << '\n';

	return 0;
}
