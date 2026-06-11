#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


int main()
{
    int n; ll k;
    cin >> n >> k;
    vector<int> to(n);
    rep(i,n) {
        cin >> to[i];
        to[i]--;
    }


    vector<int> seen(n,-1);
    vector<int> path(n);
    int s;
    int cur = 0;
    int sz = 0;
    for(;;sz++) {
        if(seen[cur] != -1) {
            s = seen[cur]; // pathの[s]~[sz-1]がcycle
            break;
        }
        else {
            seen[cur] = sz;
            path[sz] = cur;
            cur = to[cur];
        }
    }

    if(k < s) {
        cout << path[k] + 1 << endl;
    }
    else {
        k -= s;
        cout << path[s + k%(sz-s)] + 1 << endl;
    }
    return 0;
}