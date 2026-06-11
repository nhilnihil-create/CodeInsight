#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int N,K,R,S,P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    int ans = 0;
    bool add[N];
    //R-s S-p P-r

    REP(i,N){
        if(i< K){
            add[i] = true;
            if(T[i]== 's') ans+=R;
            if(T[i]== 'p') ans+=S;
            if(T[i] == 'r') ans+=P;
        }
        else{
            if(T[i]==T[i-K] && add[i-K]){
                add[i] = false;
            }
            else{ 
                add[i] = true;
                if(T[i]== 's') ans+=R;
                if(T[i]== 'p') ans+=S;
                if(T[i] =='r') ans+=P;
            }
        }
    }
    cout << ans << endl;
}