#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    string s;
    ll k;
    cin >> s >> k;

    ll len = s.length();
    vi vec;
    ll cnt = 1;
    rep(i,len-1){
        if(s[i] == s[i+1]){
            cnt++;
        }else{
            vec.push_back(cnt);
            cnt = 1;
        }
    }

    if(cnt != 0){
        vec.push_back(cnt);
    }


    // cout << "vec" << endl;
    // for(auto e: vec){
    //     cout << e << endl;
    // }

    if(vec.size() > 0){
        if(vec[0] == len){
            cout << (len * k) / 2 << endl;
        }else{
            ll ans = 0;
            for(auto e: vec){
                ans += e/2;
            }
            ans = ans * k;
            
            if(s[0] == s[len-1]){
                ll a = vec[0];
                ll b = vec[vec.size()-1];

                ll sub = a/2 + b/2 - (a+b)/2;
                sub = sub * (k-1);
                ans -= sub;
            }
            cout << ans << endl;
        }
    }else{
        cout << 0 << endl;
    }

    return 0;
}