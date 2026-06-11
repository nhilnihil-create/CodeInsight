#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;
const double PI = 3.1415926535897932384626433832;



double a,b,x;

bool safe(double ang) {
    double vol = a*a*b;
    double h = tan(ang)*a;
    if (h <= b) {
	double tri = (0.5*a*h)*a;
	return vol-tri >= x;
    } else {
	ang = PI/2 - ang;
	double y = b*tan(ang);
	double tri = 0.5*y*b*a;
	return tri >= x;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>a>>b>>x;


    double lo = 0;
    double hi = PI/2;


    for (int iter=0; iter<1000; iter++) {
	double mid = (lo+hi)/2;
	if (safe(mid)) {
	    lo = mid;
	} else {
	    hi = mid;
	}
    }

    double deg = lo*180.0/PI;
    cout<<fixed<<setprecision(15)<<deg<<endl;
    return 0;
}
