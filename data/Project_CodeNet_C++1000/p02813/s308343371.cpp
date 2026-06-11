#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n; cin >> n;
    vector<int> p(n);rep(i,n) cin >> p[i];
    vector<int> q(n);rep(i,n) cin >> q[i];
    vector<int> r(n);rep(i,n) r[i]=i+1;
    int pnum=0,qnum=0;
    bool okp=true,okq=true;
    do{
        // rep(i,n) cout<<r[i]<<" ";
        // cout << endl;
        if(okp){
             rep(i,n){
                if(p[i]!=r[i]) break;
                if(i==n-1) okp=false;
            }
            pnum++;
            // cout << "p " << pnum << endl;
        }
        if(okq){
            rep(i,n){
                if(q[i]!=r[i]) break;
                if(i==n-1) okq=false;
            }
            qnum++;
            // cout << "q " << qnum <<okq<< endl;
        }
        if(!okp && !okq) break;
    }while(next_permutation(r.begin(),r.end()));
    cout << abs(pnum-qnum) << endl;
}