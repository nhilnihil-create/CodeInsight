#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L

typedef long long ll;

void solve(){
	int a, b, h, m;
	cin >> a >> b >> h >> m;
	
	long double rad = PI * 2 * (
		(long double)h / 12.0 + ((long double)m / 60.0) / 12.0 - 
			(long double)m / 60.0);
			
	long double rsq = (long double)(a * a + b * b) - (long double)
		(2 * a * b) * cosl(rad);
		
	printf("%20.20Lf\n", sqrtl(rsq));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
