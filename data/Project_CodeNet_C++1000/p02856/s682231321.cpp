#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

pair<ll,ll> solve(ll digit, ll num)
{
    vector<ll> tmp;
    ll ans = 0;
    while(num > 1){
        if(num%2){
            tmp.push_back(digit);
            --num;
            if(tmp.size() == 2){
                ll tmpdigit = tmp.at(0) + tmp.at(1);
                ++ans;
                if(tmpdigit >= 10){
                    tmpdigit = 1 + tmpdigit%10;
                    ++ans;
                }
                tmp.clear();
                tmp.push_back(tmpdigit);
            }
        }
        digit = 2*digit;
        num /= 2;
        ans += num;
        if(digit >= 10){
            digit = 1 + digit%10;
            ans += num;
        }
    }
    if(tmp.size() == 0){
        return make_pair(digit, ans);
    }else{
        digit += tmp.at(0);
        ++ans;
        if(digit >= 10){
            digit = 1 + digit%10;
            ++ans;
        }
        return make_pair(digit, ans);
    }
}

int main()
{
    ll i,j;
    ll m;
    cin >> m;
    vector<ll> d(m);
    vector<ll> c(m);
    ll ans = 0;
    stack<ll> last;
    for(i = 0;i < m;++i){
        cin >> d.at(i) >> c.at(i);
        auto x = solve(d.at(i), c.at(i));
        ans += x.second;
        last.push(x.first);
    }
    while(last.size() > 1){
        ll digit = 0;
        digit += last.top();
        last.pop();
        digit += last.top();
        last.pop();
        ++ans;
        if(digit >= 10){
            digit = 1 + digit%10;
            ++ans;
        }
        last.push(digit);
    }
    cout << ans << endl;

    return 0;
}