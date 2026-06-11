#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main(){
    long long n, m, fr, to, s, t;
    cin >> n >> m;
    vector<vector<long long> > g(3 * 1e5 + 3);
    for(int i = 0; i < m; ++i){
        cin >> fr >> to;
        fr--, to--;
        g[fr].push_back(to + n);
        g[fr + n].push_back(to + 2 * n);
        g[fr + 2 * n].push_back(to);
    }
    cin >> s >> t;
    s--, t--;
    vector<long long> d(3 * 1e5 + 3, 1e9);
    d[s] = 0;
    vector<char> used(3 * 1e5 + 3, false);
    queue<long long> q;
    q.push(s);
    used[s] = true;
    while(!q.empty()){
        long long v = q.front();
        q.pop();
        for(long long a: g[v]){
            if(!used[a]){
                d[a] = d[v] + 1;
                q.push(a);
                used[a] = true;
            }
            if(a == t){
                cout << d[t] / 3;
                return 0;
            }
        }
    }
    cout << -1;
}
