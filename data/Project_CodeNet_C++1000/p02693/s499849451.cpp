#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    int K;
    double A,B;
    cin >> K;
    cin >> A >> B;
    int CEA,tmp;
    CEA = ceil(A/K) * K;
    if(CEA >= A && CEA <= B) cout << "OK" << endl;
    else cout << "NG" << endl;

    return 0;
}