#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    int T1,T2,A1,A2,B1,B2;
    int C1,C2;
    cin >> T1 >> T2;
    cin >> A1 >> A2;
    cin >> B1 >> B2;
    
    C1=T1*(A1-B1);
    C2=T2*(A2-B2);
    if(C1+C2==0){
        cout << "infinity" << endl;
        return 0;
    }
    
    if(abs(C1)>abs(C2) || (C1>0&&C2>0)|| (C1<0&&C2<0)){
        cout << 0 << endl;
        return 0;
    }
    if(C1+C2<0){C1*=-1;C2*=-1;}
    
    
    //cout << C1 MM C2 << endl;
    //cout << C1 + C2 << endl;
    //cout << C2/(C1 + C2) << endl;
    
    /*
    int K=0;
    REP(i,100){
        K+=C1;cout << 2*i+1 MM K << endl;
        K+=C2;cout << 2*i+2 MM K << endl;
    }*/
    int K=(-C1/(C1 + C2));
    cout << 2*K+1+((-C1)%(C1+C2)==0?-1:0) << endl;
    return 0;
}

