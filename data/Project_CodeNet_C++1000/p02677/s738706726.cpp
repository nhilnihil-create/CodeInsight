#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ENDL '\n'
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": " << a << ENDL
#define all(a) begin(a), end(a)
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

ld EPS = 1e-6;

struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};

ld to2(ld u) {
    return u * u;
}

ld dist(pt u, pt v) {
    return sqrt(to2(u.x - v.x) + to2(u.y - v.y));
}

int main()
{   _
    ld a, b; cin >> a >> b;
    pt u(0.0, a);
    pt v(0.0, b);
    lli h, m; cin >> h >> m;
    m += h * 60LL;
    ld hFrac = 1.0 / 720.0;
    ld fullAngle = 2.0 * acos(-1);
    ld mFrac = 1.0 / 60.0;
    ld hAngle = m * hFrac * fullAngle;
    m %= 60;
    ld mAngle = m * mFrac * fullAngle;
    u = u.rot(hAngle);
    v = v.rot(mAngle);
    cout << setprecision(10) << fixed << dist(u, v) << ENDL;
    return 0;
}
