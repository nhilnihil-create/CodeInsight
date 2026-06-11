#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i, s, n) for(long long i=(s);i<(long long)(n);i++)
#define all(v) v.begin(), v.end()

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<ll, ll>;

const ll INF = (1LL<<60);

int main(){

    string s; cin >> s;

    rep(i, s.size()){
        if(i%2==0){
            if(s[i]!='L') continue;
        }
        else{
            if(s[i]!='R') continue;
        }
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}