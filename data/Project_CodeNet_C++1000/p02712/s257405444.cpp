#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum=0;
int x;
int main() {
	cin >> x;
  	for (int i=1; i<=x; i++) if (i%3 && i%5) sum+=i;
  	cout << sum;
}