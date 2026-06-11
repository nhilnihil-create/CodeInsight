#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    int N;
    cin >> N;
    int X[N],Y[N];
    rep(i,N) cin >> X[i] >> Y[i];
    map<pair<int,int>,long long> m;
    rep(i,N){
        rep(j,N){
            if(i == j) continue;
            m[make_pair(X[i]-X[j],Y[i]-Y[j])]++;
        }
    }
    long long res = 0;
    for(auto it = m.begin();it != m.end();it++){
        res = max(res,it->second);
    }
    cout << N - res << endl;
    
    return 0;
}