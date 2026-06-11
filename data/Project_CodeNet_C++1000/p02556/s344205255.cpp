#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 2*10e5+10;
ll a[maxn];
ll b[maxn];
int main(){
	int n;
	cin >> n;
	int x,y;
	for(int i = 1;i <= n;i++){
		cin >> x >> y;
		a[i] = x + y;
		b[i] = x - y;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	cout << max(a[n] - a[1],b[n] - b[1]);
}