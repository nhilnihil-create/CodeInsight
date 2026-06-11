#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    while(1){
        C -= B; 
        if(C <= 0){
            cout << "Yes" << endl;
            break;
        }
        A -= D;
        if(A <= 0){
            cout << "No" << endl;
            break;
        }
    }
    
    return 0;
}