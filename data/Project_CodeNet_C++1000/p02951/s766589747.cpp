/*
 ╔═══╦═══╦═══╗
 ║╔═╗║╔══╩╗╔╗║
 ║║░║║╚══╗║║║║
 ║║░║║╔══╝║║║║
 ║╚═╝║╚══╦╝╚╝║
 ╚══╗╠═══╩═══╝
 ░░░╚╝░░░░░░░░
 */

#include <bits/stdc++.h>
#define ll					long long
#define MOD					1000000007
#define MAX					1e9
#define MIN                 -1e9
#define PI					acos(-1.0)
#define vi					vector<int>
#define vii					vector<vi>
#define vll					vector<ll>
#define mid(s,e)			(s+(e-s)/2)
#define clz(n)				__builtin_clzll(n)

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template<typename T>
void printVec(const T &v, char sep=' ') {for (auto &i: v) cout << i << sep;}
template<typename T>
void printVecPair(const T &v, char sep=' ') {for (auto &i: v) cout << i.first <<" " << i.second<< sep;}


#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int main() {
	ios::sync_with_stdio(false);
 	cin.tie(0);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",(c - (a-b) > 0 ? c-(a-b) : 0));
	return 0;
}



