#include <bits/stdc++.h>
 
using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define VPII vector<PII>
#define LD long double

string S,T;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(11);
    cerr << fixed << setprecision(6);
    cin >> S >> T;
    int cnt=0,max_cnt=0;
    R(i,S.size()-T.size()+1){
        cnt=0;
        R(j,T.size()){
            if(S[i+j] == T[j]) cnt++;
        }
        max_cnt=max(cnt,max_cnt);
    }
    cout << to_string(T.size() - max_cnt) << endl;
}
