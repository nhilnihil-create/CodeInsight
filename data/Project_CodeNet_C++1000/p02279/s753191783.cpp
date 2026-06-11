#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;

lli n;
vll p;
mat t;
vll d;

lli depth(lli x){
    if(p[x] == -1) return d[x] = 0;
    if(d[x]) return d[x];
    return d[x] = depth(p[x]) + 1;
}

int main(){
    cin >> n;
    p = vll(n,-1);
    t = mat(n);
    d = vll(n);
    for(lli i = 0;i < n;i++){
        lli node,k;
        cin >> node >> k;
        for(lli j = 0;j < k;j++){
            lli c;
            cin >> c;
            t[node].push_back(c);
            p[c] = node;
        }
    }
    for(lli i = 0;i < n;i++){
        cout << "node " << i << ": ";
        cout << "parent = " << p[i] << ", ";
        cout << "depth = " << depth(i) << ", ";
        if(p[i] == -1) cout << "root, ";
        else if(t[i].size() == 0) cout << "leaf, ";
        else cout << "internal node, ";
        cout << "[";
        for(lli j = 0;j < t[i].size();){
            cout << t[i][j];
            if(++j < t[i].size()) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}