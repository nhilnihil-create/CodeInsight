#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

ll func(ll n){
    return n * (n-1) / 2;
}

int main(){
    int N;
    cin >> N;
    map<string, ll> mp;
    rep(i, N){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    ll cnt = 0;
    for(auto p : mp){
        if(p.second >=2){
            cnt += func(p.second);
        }
    }
    cout << cnt << endl;
    return 0;
}