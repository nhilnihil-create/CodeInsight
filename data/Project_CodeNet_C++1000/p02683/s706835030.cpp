#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
const int INFTY =2147483647;

int n,m,x;
int A[13][13];
int C[13];


int solve(int i,int c,int O[]){
    if(i==n){
        bool z=true;
        REP(j,m) if(O[j]<x) z=false;
        if(z==true){
            return c;
        } 
        else return INFTY;

    }
    else{
        int a=solve(i+1,c,O);
        REP(j,m)O[j]+=A[i][j];
        int b=solve(i+1,c+C[i],O);
        REP(j,m)O[j]-=A[i][j];
        return min(a,b);
    }
}

int main(){
    int B[13]={};
    cin>>n>>m>>x;
    REP(i,n) {
        cin>>C[i];
        REP(j,m) cin>>A[i][j];
    }
    int ans=solve(0,0,B);
    if(ans==INFTY) cout<<-1<<endl;
    else cout<<ans<<endl;
}