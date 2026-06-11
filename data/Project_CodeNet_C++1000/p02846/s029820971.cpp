//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
#include<complex>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T1> bool chmax(T1 &a, const T1 &b) { if (a < b) { a = b; return true; } return false; }
template<class T1> bool chmin(T1 &a, const T1 &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD =  (int)1e9 + 7;
const double EPS = 1e-9;

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T1,T2;
	int A1,A2;
	int B1,B2;
	cin>>T1>>T2>>A1>>A2>>B1>>B2;

	A1*=T1,A2*=T2,B1*=T1,B2*=T2;

	if(A1+A2==B1+B2)
	{
		cout<<"infinity"<<endl;
		return 0;
	}
	if(A1+A2<B1+B2)
	{
		swap(A1,B1);
		swap(A2,B2);
	}
	if(B1-A1<0)cout<<0<<endl;
	else
	{
		int D=A1+A2-B1-B2;
		int T=(B1-A1)/D+1;
		T*=2;
		T--;
		if((B1-A1)%D==0)T--;
		cout<<T<<endl;
	}
	

	return 0;
}
