#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//using ll = long long;
using namespace std;

void fanc(int n, int level, pair<double, double> l, pair<double, double> r){
	if(level == n){
		printf("%.8f %.8f\n", l.first, l.second);
		return;
	}
	pair<double, double> s, t, u;
	s.first = (2.*l.first + r.first)/3;
	s.second = (2.*l.second + r.second)/3;
	fanc(n, level+1, l, s);
	
	t.first = (l.first + 2.*r.first)/3;
	t.second = (l.second + 2.*r.second)/3;
	
	
	double pi = acos(-1);
	double d60 = pi/3;
	u.first = s.first + (t.first-s.first)*cos(d60) - (t.second - s.second)*sin(d60);
	u.second = s.second + (t.first - s.first)*sin(d60) + (t.second - s.second)*cos(d60);
	fanc(n, level+1, s, u);
	fanc(n, level+1, u, t);
	fanc(n, level+1, t, r);
}

int main(){
	int n;
	cin >> n;
	pair<double, double> l(0, 0), r(100, 0);
	fanc(n, 0, l, r);
	printf("%.8f %.8f\n", r.first, r.second);
	return 0;
}
