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

ll func(string s){
    ll len = s.size();
    if(s[0] == s[len-1]){
        //sの先頭から同じ文字がつながっている個数
        ll a = 1;
        rep(i, len){
            if(s[i] == s[i+1]) a++;
            else break;
        }
        //sの末尾から同じ文字がつながっている個数
        ll b = 1;
        for(int i = len-1; i >= 0; i--){
            if(s[i] == s[i-1]) b++;
            else break;
        }

        ll val = (a/2) + (b/2) - (a+b)/2;
        return val;
    }else{
        return 0;
    }
}

int main(){
    string s;
    ll K;
    cin >> s >> K;
    ll len = (ll)s.size();
    //書き換えなければ行けない文字数
    ll ans = 0;
    //S内で書き換えなければならない文字数
    ll count = 0;
    //Sの文字がすべて同じ場合はコーナーケースとして扱う
    bool is = true;
    rep(i, len-1){
        if(s[i] != s[i+1]) is = false;
    }
    if(is){
        ans = len * K / 2;
        cout << ans << endl;
        return 0;
    }
    //S内で書き換えなければならない個数のカウントを行う
    rep(i, len-1){
        if(s[i] == s[i+1]){
            ll val = 1;
            while(i < len && s[i] == s[i+1]){
                i++;
                val++;
            }
            count += val / 2;
        }
    }
    ans = count * K;
    //Sの先頭と末尾の文字が一致している場合の処理
    if(s[0] == s[len-1] && len > 1){
        ll a = 1, b = 1;
        rep(i, len-1){
            if(s[i] == s[i+1]) a++;
            else break;
        }
        for(int i = len-1; i > 0; i--){
            if(s[i] == s[i-1]) b++;
            else break;
        }
        ll sub = a/2 + b/2 - (a+b)/2;
        sub *= (K-1);
        ans -= sub;
    }
    cout << ans << endl;
    return 0;
}