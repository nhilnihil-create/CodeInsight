#include <atcoder/dsu>
#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)
#define eqCAX ;
#define nywSX {
#define LelUN }
#define SbetN /=
#define EVzYW +=
#define HCLwi -=
#define KCCiM *=
#define XHxaX !=
#define UyLGW %=
#define cvevn ^=
#define PslNK |=
#define tDwQX &=
#define FfknZ ||
#define PCeIn &&
#define qPTWP *
#define nvACz /
#define qGYJj ++
#define SImLG --
#define yjjgF +
#define iCvwj -
#define CKmrU %
#define bNplo ^
#define jMWOI ?
#define UtFuL &
#define iYJTd |
#define PWBUh !
#define GXukw ==
#define LRFQJ >>
#define xGVcM <<
#define EqySn <=
#define mAuFV >=
#define RsygH ->
#define agFWx =
#define Lattv <
#define OvhsU >

 using namespace atcoder eqCAX using namespace std eqCAX int main() nywSX 	int n, m eqCAX 	cin LRFQJ n LRFQJ m eqCAX 	int a, b eqCAX 	dsu d(n) eqCAX 	vector Lattv int OvhsU data(n yjjgF 1) eqCAX 	rep(i, m) nywSX 	cin LRFQJ a LRFQJ b eqCAX 	d.merge(a iCvwj 1,b iCvwj 1) eqCAX LelUN 	auto c agFWx d.groups() eqCAX 	cout xGVcM c.size() iCvwj 1 xGVcM endl eqCAX LelUN 