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

    ll A[N];
    ll B[N];
    rep(i, N - 1){
        cin >> B[i];
    }
    B[N - 1] = 100001;

    ll ans = 0;
    rep(i, N){
        if(i == 0){
            A[i] = B[i];
        }else{
            A[i] = min(B[i - 1], B[i]);
        }
        ans += A[i];
    }

    cout << ans << endl;

    return 0;
}