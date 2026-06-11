#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    int cnt = 0;
    rep(i,n){
        if(s[i] == 'o'){
            cnt++;
            i += c;
        }
    }
    if(cnt > k){
        cout << endl;
        return 0;
    }

    int l[k], r[k];
    cnt = 0;
    rep(i,n){
        if(s[i] == 'o'){
            l[cnt] = i;
            cnt++;
            i += c;
        }
    }
    cnt = k - 1;
    drep(i,n){
        if(s[i] == 'o'){
            r[cnt] = i;
            cnt--;
            i -= c;
        }
    }

    rep(i,k){
        if(l[i] == r[i]){
            cout << l[i] + 1 << endl;
        }
    }

    return 0;
}


