#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

//deque型の問題、flag管理も重要
int main(){
    string s;
    cin >> s;
    deque<char> dS(s.size());
    for(int i = 0;i < s.size();++i)
        dS[i] = s[i];
    ll N;
    cin >> N;

    int fla=0;

    for(ll i = 0;i < N;i++){
        int query;
        cin >> query;
        if(query == 2){
            int zengo;
            char c1;
            cin >> zengo >> c1;
            --zengo;
            if(fla) zengo = 1 - zengo;
            if(zengo)
                dS.push_back(c1);
            else
                dS.push_front(c1);
        }else{
            fla = 1 - fla;
        }
    }

    if(fla)
        reverse(dS.begin(),dS.end());
    for(auto c:dS)
        cout << c;
    cout << endl;
}