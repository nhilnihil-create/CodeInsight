#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int N;
    cin >>N;
    vector<int> P(N);
    vector<int> Q(N);
    vector<int> A(N);
    iota(A.begin(),A.end(),1);
    REP(i,N) cin >> P.at(i);
    REP(i,N) cin >> Q.at(i);


    int p = 1;
    int q = 1;
    int k = 1;
    do{
        bool isp = true;
        bool isq = true;
        REP(i,N){
            if(A[i] != P[i]) isp = false;
            if(A[i] != Q[i]) isq = false;
        }
        if(isp) p = k;
        if(isq) q = k;
        k++;
    }while(next_permutation(A.begin(),A.end()));
    cout << abs(p-q) << endl;
    return 0;
}