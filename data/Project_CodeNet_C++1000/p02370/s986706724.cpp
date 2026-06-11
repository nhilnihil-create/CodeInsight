#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <list>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define sz(x) int(x.size())

typedef long long ll;

using namespace std;

/*******-c++14 don't include-*******/
template<typename T>
T gcd(T a, T b){if( b == 0)return a; return gcd(b, a%b); }
template<typename T>
T lcm(T a, T b){return a*b/gcd(a,b); }
/*******---------------------*******/

static const int INTINF = (2147483647);
static const ll LLINF = (1ll<<32);
static const int MAX = 100001;

int main(int argc, const char * argv[]) {
    // input from txt

    /////////
    //write//
    /////////
    
    int v, e;
    cin >> v >> e;
    vector<int> glaph[MAX];
    int degree[MAX];
    bool col[MAX];
    
    rep(i, e){
        int s, t;
        cin >> s >> t;
        glaph[s].push_back(t);
    }
    
    fill(degree, degree+v, 0);
    fill(col, col+v, false);
    
    rep(i, v){
        rep(j, glaph[i].size()){
            degree[glaph[i][j]]++;
        }
    }
    
    queue<int> res;
    rep(i, v){
        if(degree[i] == 0 && !col[i]){
            queue<int> q;
            q.push(i);
            col[i] = true;
            while(!q.empty()){
                int u = q.front(); q.pop();
                res.push(u);
                rep(j, glaph[u].size()){
                    int u2 = glaph[u][j];
                    degree[u2] --;
                    if(degree[u2] == 0 && !col[u2]){
                        col[u2] = true;
                        q.push(u2);
                    }
                }
            }
        }
    }
    
    while(!res.empty()){
        int foo = res.front(); res.pop();
        cout << foo;
        cout << endl;
    }
    
    return 0;
}

