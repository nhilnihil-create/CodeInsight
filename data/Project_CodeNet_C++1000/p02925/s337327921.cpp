/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 62;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
int main(void){
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n - 1));
    rep(i, n){
        rep(j, n - 1){
            cin >> vec[i][j];
            vec[i][j]--;
        }
        reverse(all(vec[i]));
    }
    int ans = 0;
    set<int> nextday;
    rep(i, n) nextday.insert(i);
    while(true){
        set<int> today = nextday;
        nextday.clear();
        vector<int> played(n, 0);
        bool f = false;
        for(auto &i : today){
            if(vec[i].size() == 0) continue;
            if(vec[vec[i].back()].size() == 0) continue;
            if(vec[vec[i].back()].back() == i){
                if(played[i] || played[vec[i].back()]){
                    //cout <<"ff "<<  i << " " << vec[i].back() << endl;
                    if(nextday.find(vec[i].back()) == nextday.end()){
                        nextday.insert(i);
                    }
                } else {
                    //cout << i << " " << vec[i].back() << endl;
                    played[vec[i].back()] = 1;
                    played[i] = 1;
                    nextday.insert(i);
                    nextday.insert(vec[i].back());
                    vec[vec[i].back()].pop_back();
                    vec[i].pop_back();
                    
                    f = true;
                }
            }
        }
        if(!f){
            cout << -1 << endl;
            return 0;
        }
        ans++;
        bool fin = true;
        rep(i,n){
            if(vec[i].size() != 0){
                fin = false;
                break;
            }
        }
        if(fin){
            break;
        }
    }
    cout << ans << endl;
}