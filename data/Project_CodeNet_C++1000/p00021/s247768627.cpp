//二次元幾何ライブラリ
#include <iostream>
#include <cstdio>
#include <complex>
#include <map>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define MC make_pair
#define ML make_pair 
#define X real()
#define Y imag()
typedef double D;
typedef bool B;
typedef complex<D> P;   //点
typedef complex<D> V;   //ベクトル
typedef pair<P,P>  L;   //直線
typedef pair<P,D>  C;   //円
typedef vector<P>  Pol; //多角形

//変数名定義
const D INF = 1e100;
const D EPS = 1e-12;
const D PI = acos(-1);

template<class T> bool operator==(T a, T b){return abs(a - b )< EPS;}
template<class T> int sig(T r) {return (r==0||r==-0) ? 0 : r > 0 ? 1 : -1;}

P p3,p4;
int num;

// ベクトルaの絶対値を求める
// D Length = abs(a);

// 2点a,b間の距離を求める
// D Distance = abs(a-b); 

// 内積 (Inner Product) : a・b = |a||b|cosθ 1
D IP(V a, V b) {
	return (a.real() * b.real() + a.imag() * b.imag());
}

// 外積 (Exterior Product) : |a×b| = |a||b|sinθ 2
D EP(V a, V b) {
	return (a.real() * b.imag() - a.imag() * b.real());
}

// 点の進行方向について 3
int ccw(P a, P b, P c) {              //点aと点bが与えられた問いに
  b -= a; c -= a;
  if (EP(b, c) > 0)   return +1;      // counter clockwise
  if (EP(b, c) < 0)   return -1;      // clockwise
  if (IP(b, c) < 0)     return +2;    // c--a--b on line
  if (norm(b) < norm(c)) return -2;   // a--b--c on line
  return 0;                           // a--c--b on line  aとbの線分判定はこれ
}

// 2直線の垂直判定 : a⊥b <=> IP(a, b) = 0 4needs1
B IsVecular(L l1, L l2) {
	return IP(l1.first-l1.second, l2.first-l2.second)==0.0;
}

// 2直線の平行判定 : a//b <=> EP(a, b) = 0 5needs2
B IsParallel(L l1, L l2) {
	return abs(EP(l1.first-l1.second, l2.first-l2.second))<EPS;
}


//example : v1 = V(5.0,-3.0) p1=P(0.0,4.0)
int main(void){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		P points[4];
		for(int j=0;j<4;j++)
			cin >> points[j].X >> points[j].Y;
		L l1,l2;
		l1=ML(points[0],points[1]);
		l2=ML(points[2],points[3]);
		if(IsParallel(l1,l2))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}