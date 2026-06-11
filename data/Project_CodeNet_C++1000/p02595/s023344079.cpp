#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i=0; i < (long long)(n); i++)

int main(){
    int N,count=0;
    long long D;
    cin >> N >> D;
    vector<long long> x(N),y(N); 
    rep(i,N){
        cin >> x.at(i) >> y.at(i);
    }
    rep(i,N){
        if(x.at(i)*x.at(i) + y.at(i)*y.at(i) <= D*D){
            count++;
        }
    }
    cout << count << endl;
}