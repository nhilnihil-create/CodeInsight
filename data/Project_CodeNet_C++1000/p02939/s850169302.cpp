#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;
// int64_t INF = 9223372036854775807;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    string s;
    cin >> s;
    // 1つ単位でわけていく
    // 隣と同じだったら2つくっつける
    int64_t res = 0;
    if(s.size()==1){
        cout << 1 << endl;
        return 0;
    }
    rep(i,s.size()-2){
        if(s.at(i) == '#') continue;
        if(s.at(i) == s.at(i+1)){
            s.at(i+1) = '#';
            s.at(i+2) = '#';
            res+=2;
            // cout << s << endl;
        }else{
            res++;
        }
    }

    char last1 = s.at(s.size()-1);
    char last2 = s.at(s.size()-2);
    if(last1!='#') res++;
    if(last2!='#') res++;
    if(last1!='#' && last2!='#' && last1==last2) res--;
    cout << res << endl;
}