#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>

#define REP(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (2e9)
// cout << setprecision(10)

using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

char c;
int main(void){
    map<char, int> m;
    REP(i,4) {
        cin >> c;
        m[c]++;
    }

    for(auto it : m){
        if(it.second != 2){
            cout << "No" << endl;
            return 0;    
        }    
    }

    if(m.size() == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

