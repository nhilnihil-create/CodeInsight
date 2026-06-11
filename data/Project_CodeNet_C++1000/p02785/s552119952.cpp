#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long

int main(){
    int N,K;
    cin >> N >> K;
    vector<ll> monhp(N);
    rep(i,N){
        cin >> monhp.at(i);
    }
    stable_sort(monhp.begin(),monhp.end(),greater<ll>());
    if(K!=0){
        int num = min(K,N);
        vector<ll> hissatu(num);
        copy(monhp.begin(),monhp.begin()+num,hissatu.begin());
        cout <<  accumulate(monhp.begin(),monhp.end(),0LL) - accumulate(hissatu.begin(),hissatu.end(),0LL) << endl;
    }else{
        cout <<  accumulate(monhp.begin(),monhp.end(),0LL) << endl;
    }
}


