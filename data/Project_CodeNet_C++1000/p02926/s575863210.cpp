#include<bits/stdc++.h>
using namespace std;

struct P {
	double x, y;
} p[111], cur, s, t, tt;

int n;

double len(P p) {
	return sqrt(1.*p.x*p.x + 1.*p.y*p.y);
}

double dot(P p1, P p2) {
	return 1.*p1.x*p2.x + 1.*p1.y*p2.y;
}

int cmp(const P &a, const P &b) {
	return atan2(a.y, a.x) < atan2(b.y, b.x);
}

int main() {
	scanf("%d", &n);
	s.x = s.y = 0;
	for(int i=0;i<n;i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		s.x += p[i].x; s.y += p[i].y;
	}
	sort(p, p+n, cmp);
	
	double ans = 0;
	for(int i=0;i<n;i++) {
		t.x = t.y = 0;
		for(int j=i;j<n;j++) {
			t.x+=p[j].x;
			t.y+=p[j].y;
			ans = max(ans, len(t));
			tt.x = s.x - t.x;
			tt.y = s.y - t.y;
			ans = max(ans, len(tt));
		}
	}
	printf("%.12lf\n", ans);
	
	return 0;
}