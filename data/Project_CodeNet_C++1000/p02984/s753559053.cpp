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
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll N;
    cin >> N;

    ll A[N];
    ll rainSum = 0;
    rep(i, N){
        cin >> A[i];
        rainSum += A[i];
    }

    ll ans[N];
    ll sum;
    sum = A[0] + A[N - 1];
    for(ll i = 2; i < N - 1; i += 2){
        sum += A[i];
    }
    ans[0] = sum * 2 - rainSum;//cout << "sum: " << sum * 2 << ", rainSum: " << rainSum << endl;
    for(ll i = N - 1; i > 0; i--){
        ans[i] = (A[i] - ans[(i + 1) % N] / 2) * 2;
    }

    rep(i, N){
        if(i != 0){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;

    return 0;
}