#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

ll dp[100000];

int main(void){
    ll n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<ll> ans;
    bool flag;
    rrep(i, n, 1){
        if(s[i] == '1')continue;
        flag = true;
        rrep(j, min(i, m), 1){
            if(s[i - j] == '0'){
                i = i - j + 1;
                ans.push_back(j);
                flag = false;
                break;
            }
        }
        if(flag){
            cout << -1 << endl;
            return 0;
        }
    }

    while(ans.size()){
        ll tmp = ans.back();
        ans.pop_back();
        cout << tmp << " ";
    }

    cout << endl;
    return 0;
}
