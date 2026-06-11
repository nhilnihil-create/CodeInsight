#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll calc(ll A){
    return (ll)(A*1.08);
}
int main() { 
    ll N, A;
    cin >> N ;
    A = (ll) N/1.08;
    if(calc(A-1)==N) cout << A-1 << endl;
    else if(calc(A-0)==N) cout << A-0 << endl;
    else if(calc(A+1)==N) cout << A+1 << endl;
    else cout << ":(" << endl;
}