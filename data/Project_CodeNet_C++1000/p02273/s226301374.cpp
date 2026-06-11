#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define PI 3.141592653589793

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

struct point{
		double x;
		double y;
};

void coho(int d, point a, point b){
	double p6 = 60 * PI /180.0;
	if(d == 0) return;
	double x1 = (b.x -a.x)/3;
	double y1 = (b.y -a.y)/3;
	point s, t, u;
	s.x = x1 +a.x;
	s.y = y1 + a.y;
	u.x = x1*2 + a.x;
	u.y = y1*2 + a.y;
	t.x = (u.x - s.x)*cos(p6) - (u.y - s.y)*sin(p6) + s.x;
	t.y = (u.x - s.x)*sin(p6) + (u.y - s.y)*cos(p6) + s.y;
	coho(d-1, a, s);
	cout << s.x <<" "<< s.y << endl;
	coho(d-1, s, t);
	cout << t.x <<" "<< t.y << endl;
	coho(d-1, t, u);
	cout << u.x << " " << u.y << endl;
	coho(d-1, u, b);
}

int main(){
	int n;
	cin >> n;
	point a, b;
	a.x = 0;
	a.y = 0;
	b.x = 100;
	b.y = 0;
	cout << a.x << " " << a.y << endl;
	coho(n, a, b);
	cout << b.x << " " << b.y << endl;
}

