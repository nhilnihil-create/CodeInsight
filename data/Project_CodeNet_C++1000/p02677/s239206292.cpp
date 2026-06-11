#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

#define mp make_pair
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

void setIO(string name = ""){
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

#define PI 3.14159265358979323846264338327950L

int main(){
 	ios_base::sync_with_stdio(0); cin.tie(0); 
	// setIO();
	long double a,b,h,m;
	cin >> a >> b >> h >> m;
	long double rad=PI* 2 * ((long double)h/ 12.0 + ((long double)m/ 60.0) / 12.0 - (long double)m/ 60.0);
	long double rsq= (long double)(a*a+b*b) - (long double)(2 *a*b) *cosl(rad);
	printf("%20.20Lf\n",sqrtl(rsq));

}




