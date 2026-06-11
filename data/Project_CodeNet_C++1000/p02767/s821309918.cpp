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

    ll X[N];
    ll sum = 0;
    ll centerA, centerB;
    rep(i, N){
        cin >> X[i];
        sum += X[i];
    }
    centerA = sum / N;
    centerB = centerA + 1;

    ll ansA = 0, ansB = 0;
    rep(i, N){
        ansA += (X[i] - centerA) * (X[i] - centerA);
        ansB += (X[i] - centerB) * (X[i] - centerB);
    }

    cout << min(ansA, ansB) << endl;

    return 0;
}