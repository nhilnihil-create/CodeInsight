#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cmath>

#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define llrep(i,j,k) for(long long int i=j;i<(long long int)k;i++)
#define Sort(x) sort(x.begin(),x.end()); 
#define vi vector<int>
#define vvi vector<vector<int>> 
#define ll long long
int mod=1e9+7;
const int INF = 1e9;

using namespace std;


int main(void) {
	int n, m;

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		vector<int> v(n), vv(m);
		int suma = 0, sumb = 0;
		rep(i, 0, n) {
			cin >> v[i];
			suma += v[i];
		}
		rep(i, 0, m) {
			cin >> vv[i];
			sumb += vv[i];
		}
		Sort(v);
		Sort(vv);

		if (suma > sumb) {
			bool judge = false;
			int x = suma - sumb;
			if (x % 2 == 1) {
				cout << -1 << endl;
				continue;
			}
			rep(i, 0, n) {
				rep(j, 0, m) {
					if (x/2 == v[i] - vv[j]) {
						judge = true;
						cout << v[i] <<" "<< vv[j] << endl;
						goto AWAY;
					}
				}
			}
			if (!judge)cout << -1 << endl;
		}
		else if (suma < sumb) {
			bool judge = false;
			int x = sumb - suma;
			if (x % 2 == 1) {
				cout << -1 << endl;
				continue;
			}
			rep(i, 0, n) {
				rep(j, 0, m) {
					if (x/2 == vv[j] - v[i]) {
						judge = true;
						cout << v[i] <<" "<< vv[j] << endl;
						goto AWAY;
					}
				}
			}
			if (!judge)cout << -1 << endl;
		}
		else {
			bool judge = false;
			rep(i, 0, n) {
				rep(j, 0, m) {
					if (v[i] == vv[j]) {
						cout << v[i] <<" "<< vv[j] << endl;
						goto AWAY;
					}
				}
			}
			if (!judge)cout << -1 << endl;
		}

	AWAY:;
	}




	


	return 0;
}