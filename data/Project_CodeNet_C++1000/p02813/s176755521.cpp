#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main(void)
{
    ll n, dic_num = 1, dic_num_p, dic_num_q;
    cin >> n;
    vector<ll> p(n), q(n), dic(0);
    for(ll i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    for(ll i = 0; i < n; i++) {
        cin >> q.at(i);
        dic.push_back(i + 1);
    }

    do {
        bool check_p = true, check_q = true;

        for(ll i = 0; i < n; i++) {
            if(dic.at(i) != p.at(i)) {
                check_p = false;    break;
            }
        }

        for(ll i = 0; i < n; i++){
            if(dic.at(i) != q.at(i)) {
                check_q = false;    break;
            }
        }

        if(check_p)
            dic_num_p = dic_num;
        if(check_q)
            dic_num_q = dic_num;

        dic_num++;

    } while ( next_permutation(dic.begin(), dic.end()) );

    cout << abs(dic_num_p - dic_num_q);
    
    return 0;
}