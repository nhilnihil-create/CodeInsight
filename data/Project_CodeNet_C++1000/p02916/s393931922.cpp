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

    ll A[N + 1];
    ll B[N + 1];
    ll C[N + 1];
    REP(i, N){
        cin >> A[i];
    }
    REP(i, N){
        cin >> B[i];
    }
    REP(i, N - 1){
        cin >> C[i];
    }

    ll lastMeal = -1;
    ll meal = -1;
    ll ans = 0;
    REP(i, N){
        lastMeal = meal;
        meal = A[i];
        ans += B[meal];
        if(meal - 1 == lastMeal){
            ans += C[lastMeal];
        }
    }

    cout << ans << endl;

    return 0;
}