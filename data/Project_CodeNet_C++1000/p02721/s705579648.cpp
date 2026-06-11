#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(){
    int n, k, c; cin >> n >> k >> c;
    string s; cin >>  s;
    vector<int> front(n,-1), back(n,-2);

    int count = 1;
    for(int i = 0; i < n; ){
        if(s[i] == 'x'){ i++; continue; }
        front[i] = count;
        count++;
        i += c+1;
    }
    count = k;
    for(int i = n-1; i >= 0; ){
        if(s[i] == 'x'){ i--; continue; }
        back[i] = count;
        count--;
        i -= c+1;
    }
    rep(i,n) if(front[i] == back[i]) cout << i+1 << endl;
    return 0;
}