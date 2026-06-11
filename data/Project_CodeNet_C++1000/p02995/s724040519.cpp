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


ll gcd(ll a, ll b){
    return b != 0 ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b){
   return a * b / gcd(a, b);
}

int main(){
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll unDivA = 0;
    ll unDivB = 0;
    ll divByC, divByD, divByBoth;
    ll lcmCD = lcm(C, D);
    divByC = (A - 1) / C;
    divByD = (A - 1) / D;
    divByBoth = (A - 1) / lcmCD;
    unDivA = (A - 1) - (divByC + divByD - divByBoth);
    divByC = B / C;
    divByD = B / D;
    divByBoth = B / lcmCD;
    unDivB = B - (divByC + divByD - divByBoth);

    cout << unDivB - unDivA << endl;

    return 0;
}
