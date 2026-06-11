#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main() {
    string s;cin>>s;
    int n = s.size();

    vec ans(n,0);

    int even_num,cnt=0;
    for(int i=0; i<n; i++){
        if(s.at(i)=='R'){
            cnt++;
            continue;
            }else{
            if(cnt%2==0)
            {
                even_num = (cnt)/2;
                }else{
                    even_num = (cnt-1)/2;
                    }
            int odd_num = cnt - even_num;
            ans[i] += even_num;
            ans[i-1] += odd_num;
            cnt = 0;
             }
    }

    
    for(int i=n-1; i>-1; i--){
        if (s[i] == 'L'){
            cnt ++;
            continue;
        }else{
            if(cnt%2==0){
                even_num = (cnt)/2;
                }else{
                    even_num = (cnt-1)/2;
                    }
            int odd_num = cnt - even_num;
            ans[i] += even_num;
            ans[i+1] += odd_num;
            cnt = 0;
        }
    }

    rep(i,n) cout<<ans[i]<<" ";

}