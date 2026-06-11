#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;
const int IINF = INT_MAX;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000000000
int n;

int main(){
    double a,b,x;
	cin >> a >> b >> x;
	
	double s = x/a;
	double ans = 0;
	if(s >= a*b/2){
		double h = (a*b-s)*2/a;
		ans = atan2(h,a); 
	}else{
   		 double k = 2*s/b;
   		 ans = atan2(b,k);
    }
    double pai = acos(-1);
    cout << fixed <<  setprecision(7) << ans/(2*pai)*360 << endl; 
    return 0;	
}