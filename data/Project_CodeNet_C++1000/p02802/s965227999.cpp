#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int N,M;
    cin >> N >> M;
    int P[M];
    string S[M];
    REP(i,M) cin >> P[i] >> S[i];
    int ac = 0;
    int wrong[N];
    int wa = 0;
    bool checked[N];
    REP(i,N) checked[i] = false;
    REP(i,N) wrong[i] = 0;

    REP(i,M){
        int p = P[i];
        p--;
        if(!checked[p]){
            if(S[i] == "AC"){
                ac++;
                checked[p] = true;
                wa += wrong[p];
            }
            else if(S[i] == "WA") wrong[p]++;
        }
    }
    cout << ac << " " << wa << endl;
}