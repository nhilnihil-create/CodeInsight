#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll N;
    cin >> N;

    double x[N + 1];
    double y[N + 1];
    REP(i, N){
        cin >> x[i] >> y[i];
    }

    ll Nfac = 1;
    vector<ll> order;
    REP(i, N){
        Nfac *= i;
        order.push_back(i);
    }

    double a, b;
    double ans = 0;
    do{
        a = x[order[0]];
        b = y[order[0]];
        REP(i, N - 1){
            ans += sqrt((a - x[order[i]]) * (a - x[order[i]]) + (b - y[order[i]]) * (b - y[order[i]]));
            a = x[order[i]];
            b = y[order[i]];
        }
    }while(next_permutation(order.begin(), order.end()));

    cout << std::fixed << std::setprecision(15) << ans / (double)Nfac << endl;

    return 0;
}