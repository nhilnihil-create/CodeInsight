#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    string s; cin >> s;

    int n = s.size();
    V<int> ans(n);

    for(int i = 0; i < 2; i++){
        {
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(s[j] == 'R') cnt++;
                else{
                    ans[j] += cnt / 2;
                    ans[j - 1] += (cnt + 1) / 2;
                    cnt = 0;
                }
            }
        }
        reverse(ALL(ans));
        reverse(ALL(s));
        for(int j = 0; j < n; j++){
            if(s[j] == 'L') s[j] = 'R';
            else s[j] = 'L';
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }

    return 0;
}
