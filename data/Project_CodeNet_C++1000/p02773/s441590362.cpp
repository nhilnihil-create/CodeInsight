#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
    ll N;
    cin >> N;
    string S;
    ll cnt=0;
    map<string,ll> data;
    for(int i=0;i<N;i++){
        cin >> S;
        data[S]++;
        cnt=max(cnt,data[S]);
    }
    for(auto p:data) {
        auto k=p.first;
        auto v=p.second;
        if(v==cnt) {
            cout << k << endl;
        }
        
    }
    
    
}
