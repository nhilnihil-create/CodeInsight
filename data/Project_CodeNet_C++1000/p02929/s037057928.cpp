#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << 0 << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    int Ans=1;
    string T=S;
    REP(i,2*N){
        if(i==0){
            T[i]='L';
            continue;
        }
        if(S[i-1]==S[i]){
            T[i]=T[i-1]^'L'^'R';
        }else{
            T[i]=T[i-1];
        }
    }
    //REP(i,2*N){cout << T[i] << " ";}cout << endl;
    if(T[2*N-1]=='L')GOODBYE;
    if(S[0]=='W')GOODBYE;
    if(S[2*N-1]=='W')GOODBYE;
    int L=0,R=0;
    REP(i,2*N){
        if(T[i]=='L'){
            L++;
        }else{
            R++;
        }
    }
    if(L!=R)GOODBYE;
    L=0;R=0;
    REP(i,2*N){
        if(T[i]=='L'){
            L++;
        }else{
            Ans=(Ans*L)%MOD;
            L--;
        }
        if(L<0)GOODBYE;
    }
    REP(i,N){
        Ans=(Ans*(i+1))%MOD;
    }
    cout << Ans << endl;
    return 0;
}   
