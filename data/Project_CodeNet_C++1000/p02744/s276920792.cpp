#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((int)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;




////////////////////////////////////////////////////////

ll N;
set<string> se;

void saiki(string s, char c){
    if(sz(s) == N){
        se.insert(s);
    }else{
        for(char d = 'a'; d <= c+1; d++){
            string t = s;
            t.push_back(d);
            if(d > c) saiki(t, c+1);
            else saiki(t, c);
        }
    }
}

int main() {
    cin >> N;
    string s = "a";
    saiki(s, 'a');
    for(auto t : se){
        co(t);
    }

    return 0;
}
