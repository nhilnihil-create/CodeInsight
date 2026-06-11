#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define pis pair<int, string>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
string S;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S;
    int lb = 0, ub = N;
    while(ub - lb > 1){
        int len = (ub + lb) / 2;

        bool flag = false;
        map<string, int> st;
        for(int i = len; i <= S.length() - len; ++i){
            st[S.substr(i, len)]++;
        }
        for(int i = 0; i < S.length() - len; ++i){
            if(st[S.substr(i, len)] > 0) flag = true;
            if(i + len * 2  - 1 < S.length()) st[S.substr(i + len, len)]--;
        }
        if(flag) lb = len;
        else ub = len;
    }
    cout << lb << endl;
    return 0;
}