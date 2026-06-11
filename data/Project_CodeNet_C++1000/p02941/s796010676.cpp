#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include<string>
#include<utility>

#define lli long long
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define rep0(i,j) for(lli i=0;i<j;i++)
#define rep1(i,j) for(lli i=1;i<=j;i++)
#define rep0d(i,j) for(lli i=j-1;i>=0;i--)
#define MAX 1000000007

using namespace std;


bool cmpf(pair<lli, lli> left, pair<lli, lli> right) {
	return left.first < right.first;
}


int main() {
	lli n;
	cin >> n;
	vector<lli> a(n),b(n);
	rep0(i, n)cin >> a[i];
	rep0(i, n)cin >> b[i];
	lli ans=0;
	while (1) {
		lli temp = 0;
		rep0(i, n) {
			if (b[i] > b[(i - 1 + n) % n] + b[(i + 1 + n) % n]) {
				if (a[i] < b[i]) {
					temp += (b[i] - a[i]) / (b[(i - 1 + n) % n] + b[(i + 1 + n) % n]);
					b[i]=(b[i] - a[i]) % (b[(i - 1 + n) % n] + b[(i + 1 + n) % n])+a[i];
				}
			}
		}
		ans += temp;
		if (temp == 0)break;
	}
	rep0(i, n) {
		if (b[i] != a[i]) {
			cout << -1;
			return 0;
		}
	}
	cout <<  ans << endl;
}
