#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    
    int int_query;
    int reversed = 0;
    REP(i,Q){
        cin >> int_query;
        if(int_query==1){
            reversed++;

        }else{
            int f;
            char q;
            cin >> f >> q;
            if((reversed + f)%2==1){
                S = q + S;
            }else{
                S += q;
            }
        }
    }

    if(reversed%2 == 1){
        string S_ = "";
        REP(i,(int)S.size()){
            S_+= S[(int)S.size()-1-i];
        }
        S = S_;
    }

    cout << S << endl;
    return 0;
    
}