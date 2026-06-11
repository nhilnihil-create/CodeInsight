#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <math.h>
#include <map>
#include <numeric>
#include <stack>
#include <queue>
#include <functional>
#include <stdio.h>
#define ll long long
#define pl pair<ll,ll>
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vvvl vector<vector<vector<ll> > >
#define vd vector<double>
#define vvd vector<vector<double> >
#define vvvd vector<vector<vector<double> > >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define vvvb vector<vector<vector<bool> > >
#define rep(i,a) for(ll i = 0;i<a;++i)
#define rep1(i,a) for(ll i = 1;i<a;++i)
#define rrep(i,a) for(ll i = a;i>=0;--i)
#define mod 1000000007
#define inf 10010010010
using namespace std;

int main(){
	ll h, w, a, b;
	cin >> h >> w >> a >> b;
	rep(i, h){
		rep(j, w){
			if (i < b && j < a || i >= b && j >= a) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
	return 0;
}