#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    rep(i, s.length()){
        if(s.at(i) == 'D') cnt++;
        if(i != s.length()-1){
            if(s.at(i) == 'P' && s.at(i+1) == 'D') cnt++;
        }
        if(s.at(i) == '?') {
            if(i != 0){
                if(s.at(i-1) == 'P') {
                    cnt += 2;
                    s.at(i) = 'D';
                }
                else {
                    cnt++;
                    s.at(i) = 'D';
                }
            }
            else {
                cnt++;
                s.at(i) = 'D';
            }
        }
    }
    cout << s << endl;
    return 0;
}