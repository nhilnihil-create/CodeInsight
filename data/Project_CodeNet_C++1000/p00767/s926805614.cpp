#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <complex>
#include <vector>
#include <tuple>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <time.h>
#define all(c) ((c).begin(),(c).end())
#define rall(c) (c).rbegin(),(c).rend()
#define sort(v,n) sort(v,v+n)
#define vsort(v) sort(v.begin(),v.end())
#define vvsort(v) sort(v.begin(),v.end(),greater<int>())
#define ll long long
#define pb(a) push_back(a)
#define fi first
#define se second
#define inf 999999999
using namespace std;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
//---------------------------------------------------------------------------------------------//
int w, h;


int main() {
	while (cin >> h >> w, w) {
		int p = h*h + w*w;
		ll hh = 151, ww = 151;
		for (int i = 1; i < 151; i++) {//w
			for (int j = 1; j < i; j++) {//h
				if (i*i + j*j > p) {
					if (hh*hh + ww*ww > i*i + j*j) {
						hh = j; ww = i;
					}
					else if (hh*hh + ww*ww == i*i + j*j) {
						if (hh > j) {
							hh = j; ww = i;
						}
					}
				}
				else if (i*i + j*j == p && j>h) {
					if (hh*hh + ww*ww > i*i + j*j) {
						hh = j; ww = i;
					}
					else if (hh*hh + ww*ww == i*i + j*j) {
						if (hh > j) {
							hh = j; ww = i;
						}
					}
				}
			}
		}
		cout << hh << " " << ww << endl;
	}
}