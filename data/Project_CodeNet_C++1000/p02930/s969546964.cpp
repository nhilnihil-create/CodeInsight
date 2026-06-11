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
#define GOODBYE cout << "-1" << endl;return 0
#define MM <<" "<<
#define Endl endl

int Ans[514][514];

int E(int l,int r,int k){
    if(r-l==0){
        return 0;
    }
    if(r-l==1){
        Ans[l][r]=k;
        return 0;
    }
    int m=(l+r+2)/2;
    for(int j=l;j<=r;j++){
        for(int i=l;i<=r;i++){
            if(i<m && m<=j){
                Ans[i][j]=k;
            }
        }
    }
    int f;
    f=E(l,m-1,k+1);
    f=E(m,r,k+1);
    return 0;
}


signed main(){
    int N;
    cin >> N;
    int f;
    f=E(1,N,1);
    REP(i,N){
        REP(j,N){
            if(i<j){
                cout << Ans[i+1][j+1] << " ";
            }
        }cout << endl;
    }
    return 0;
}   
