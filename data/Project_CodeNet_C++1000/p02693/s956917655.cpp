#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<18;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
int n, a, b;
cin >> n >> a >> b;
while(a <= b) if(a%n == 0) return cout << "OK", 0; else a++;
cout << "NG";	
return 0;
}
