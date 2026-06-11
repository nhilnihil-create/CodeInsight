#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    string N;
    cin >> N;
    REP(i,3){
        if(N[i]-'\0' == '7'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
    
}