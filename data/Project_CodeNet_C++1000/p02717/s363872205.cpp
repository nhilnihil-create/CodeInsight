#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    int X,Y,Z;
    cin >> X >> Y >> Z;
    swap(X,Y);
    swap(X,Z);
    cout << X<< " " << Y << " "<< Z << endl;
    return 0;
}