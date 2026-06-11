#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
int main(){
    int N,sum=0;
    cin >> N;
    vector<int> A(N),B(N),C(N-1);
    rep(i,N){
        cin >> A.at(i);
    }
    rep(i,N){
        cin >> B.at(i);
    }
    rep(i,N-1){
        cin >> C.at(i);
    }
    rep(i,N){
        if(i==0){
            sum+=B.at(A.at(i)-1);
        }
        if(i!=0){
            sum+=B.at(A.at(i)-1);
        }
        if(i!=0 && A.at(i)==(A.at(i-1)+1)){
                sum+=C.at(A.at(i-1)-1);
        }
        
    }

    cout << sum << endl;

}