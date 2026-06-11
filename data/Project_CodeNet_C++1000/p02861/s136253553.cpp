#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector <int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)

int main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int n; cin >> n;
    int pos[n][2];
    REP(i, n) {
        cin >> pos[i][0] >> pos[i][1];
    }
    double sum = 0;
    REP(i, n-1) {
        FOR(j, i+1, n) {
            sum += sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0]) + (pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
        }
    }
    cout << fixed << setprecision(10) << 2*sum/n << "\n";
}
