#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,k,r,s,p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;

    int ans=0;
    queue<char> q;
    for(int i = 0; i < k; i++) {
        if(t[i]=='r'){
            ans += p;
            q.push('r');
        }
        if(t[i]=='s'){
            ans += r;
            q.push('s');
        }
        if(t[i]=='p'){
            ans += s;
            q.push('p');
        }
    }

    for(int i = k; i < n; i++) {
        if(t[i]==q.front()){
            q.pop();
            q.push('a');
        }
        else{
            if(t[i]=='r'){
                ans += p;
                q.push('r');
                q.pop();
            }
            if(t[i]=='s'){
                ans += r;
                q.push('s');
                q.pop();
            }
            if(t[i]=='p'){
                ans += s;
                q.push('p');
                q.pop();
            }
        }
    }

    cout << ans << endl;

    return 0;
}