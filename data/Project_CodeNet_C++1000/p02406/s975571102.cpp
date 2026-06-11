#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi M_PI
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    int n;
    cin >> n;
    FOR(i,1,n){
        int x = i;
        bool f = 0;
        if (x % 3 == 0) f = 1;
        while (x){
            if (x % 10 == 3) f = 1;
            x /= 10;
        }
        if (f) cout << " " << i;
    }
    cout << endl;
    return 0;
}