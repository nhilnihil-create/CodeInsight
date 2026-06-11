#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include<cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include <vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

using namespace std;

#define pi arctan(1/4)
#define r3 pow(3.0,0.5)

struct Pos{
	double x;
	double y;
};

Pos Sum(Pos p, Pos q){
	Pos r;
	r.x = p.x + q.x;
	r.y = p.y + q.y;
	return r;
}

Pos Sca(double a, Pos p){
	Pos q;
	q.x = a*p.x;
	q.y = a*p.y;
	return q;
}

void print(Pos p){
	printf("%lf %lf\n", p.x, p.y);
}

int Koch(Pos left, Pos right, int n){
	if (n != 0){
		Pos s, t, u;
		s = Sum(Sca(2.0 / 3.0, left), Sca(1.0 / 3.0, right));
		t = Sum(Sca(1.0 / 3.0, left), Sca(2.0 / 3.0, right));
		u.x = Sum(Sca(0.5, left), Sca(0.5, right)).x + Sum(Sca(r3*0.5, s), Sca(-1 * r3*0.5, t)).y;
		u.y = Sum(Sca(0.5, left), Sca(0.5, right)).y + Sum(Sca(-1 * r3 / 2, s), Sca(r3 / 2, t)).x;
		Koch(left, s, n - 1);
		print(s);
		Koch(s, u, n - 1);
		print(u);
		Koch(u, t, n - 1);
		print(t);
		Koch(t, right, n - 1);
	}
	else{
		return 0;
	}
	return 0;
}

int main(){
	int n;
	Pos p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = 100;
	p2.y = 0;
	scanf("%d", &n);
	print(p1);
	Koch(p1, p2, n);
	print(p2);
	
	return 0;
}
