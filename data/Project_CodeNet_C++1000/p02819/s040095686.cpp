#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
vector<int> init_spf(int n){
    vector<int> spf(n+1);
    for (int i = 0; i < n+1; i++){
        spf[i]=i;
    }
    for (int i = 2; i*i<=n; i++){
        if(spf[i]==i){
            for (int j = i*i; j <= n; j+=i){
                if(spf[j]==j)spf[j]=i;
            }
        }
    }
    return spf;
}
int main(){
    auto spf=init_spf(100003);
    int X;cin>>X;
    for (int i = X; ; i++){
        if(spf[i]==i){
            cout<<i<<endl;
            return 0;
        }
    }
}