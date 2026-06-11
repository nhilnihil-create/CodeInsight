#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
//#define PI 3.141592653589
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

vector<int> diff(vector<int> X){
    vector<int> Y;
    REP(i,X.size()-1){
        Y.push_back(abs(X[i]-X[i+1]));
    }
    return Y;
}

int two[1114514]={};
int twof[1114514]={};

int nCr(int n,int r){
    int R=0;
    R+=twof[n];
    R-=twof[r];
    R-=twof[n-r];
    return R==0;
}

signed main(void){
    int N;
    string a;
    vector<int> A;
    cin >> N;
    cin >> a;
    REP(i,N){
        A.push_back(a[i]-'0');
    }
    /*
    REP(i,A.size()){
        cout << A[i] << " ";
    }cout << endl;*/
    
    REP(i,N+1){
        if(i==0)continue;
        if(i%2==0)two[i]=1+two[i/2];
    }
    REP(i,N+1){
        if(i==0)continue;
        twof[i]=twof[i-1]+two[i];
    }
    
    vector<int> B = diff(A);
    if((B.size())%2==0){
        B = diff(B);
    }
    if(B.size()==1){
        cout << B[0] << endl;
        return 0;
    }
    
    
    
    
    bool one = false;
    REP(i,B.size()){
        if(B[i]==1)one=true;
    }
    
    if(one==false){
        int zero=0;
        REP(i,B.size()){
            if(nCr(B.size()-1,i)){
                zero^=B[i];
            }
        }
        
        if(zero==0){
            cout << 0 << endl;
        }else{
            cout << 2 << endl;
        }
    }else{
        REP(i,B.size()){
            if(B[i]==2){
                B[i]=0;
            }
        }
        
        int zero=0;
        REP(i,B.size()){
            if(nCr(B.size()-1,i)){
                zero^=B[i];
            }
        }
        
        if(zero==0){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
    }
    return 0;
}

