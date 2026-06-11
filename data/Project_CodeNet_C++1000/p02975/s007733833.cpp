#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    map<int,int> d;
    for (int i=0;i<N;i++){
        int a;
        cin >> a;
        if (d.find(a) == d.end()) d[a] = 1;
        else d[a]++;
    }
    bool ans = true;
    if (d.size() > 3) {
        ans = false;
    } else if (d.size() == 3) {
        int val = 0;
        bool flag = true;
        for (auto it = d.begin();it!=d.end();it++){
            val ^= it->first;
            if (it->second != N/3) flag = false; 
        }
        if (val || !flag || N%3) ans = false;
    } else if (d.size() == 2) {
        bool flag = false;
        int numzero;
        int numelse;
        for (auto it = d.begin();it!=d.end();it++){
            if (it->first == 0) {
                flag = true;
                numzero = it->second;
            } else {
                numelse = it->second;
            }
        }
        if (!flag || numzero != N/3 || numelse != N*2/3) {
            ans = false;
        }
    } else if (d.size() == 1) {
        if (d.find(0) == d.end()) ans = false;
    }
    if (ans) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}