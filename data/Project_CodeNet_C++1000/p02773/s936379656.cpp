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

    map<string, ll> m;
    ll countMax = 0;
    string S;
    rep(i, N){
        cin >> S;
        if(m.find(S) == m.end()){
            m[S] = 1;
        }else{
            m[S]++;
        }
        countMax = max(countMax, m[S]);
    }

    for(auto itr = m.begin(); itr != m.end(); itr++){
        if(itr->second == countMax){
            cout << itr->first << endl;
        }
    }

    return 0;
}