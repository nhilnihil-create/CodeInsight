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

    ll A[N + 1], B[N + 1];
    vector<pair<ll, ll> > p;
    REP(i, N){
        cin >> A[i] >> B[i];
        p.push_back(make_pair(B[i], A[i]));
    }
    sort(p.begin(), p.end(), greater<pair<ll, ll> >());

    ll t = p[0].first - p[0].second;
    bool ifSuccess = true;
    REP(i, N - 1){
        t = min(p[i].first - p[i].second, t - p[i].second);
    }
    if(t < 0){
        ifSuccess = false;
    }
    if(ifSuccess){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
