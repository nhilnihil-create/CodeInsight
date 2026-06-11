#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N; cin>>N;
    vector<bitset<30>> a(N);
    vector<bitset<30>> ans(N);
    int mx=0;
    for (int i = 0; i < N; i++){
        int tmp; cin>>tmp;
        a[i]=tmp;
        mx=max(tmp,mx);
    }
    int mxbit=0;//最大ビット数
    int tmp=2;
    while(mx/tmp>0){
        tmp*=2;
        mxbit++;
    }
    for (int i = 0; i <= mxbit; i++){
        int sum=0;
        for (int j = 0; j < N; j++){
            sum=(sum+a[j][i])%2;
        }
        for (int j = 0; j < N; j++){
            ans[j][i]=(sum+a[j][i])%2;
        }
    }
    for (int i = 0; i < N; i++){
        cout<<ans[i].to_ulong()<<" ";
    }
}