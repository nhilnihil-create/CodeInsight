#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> RES;

void rec(int keta,ll now){
    RES.push_back(now);
    if(keta==10) return;

    if(now%10 != 0)rec(keta+1,now*10+now%10-1);
    rec(keta+1,now*10+now%10);
    if(now%10 != 9)rec(keta+1,now*10+now%10+1);
}

int main(){
    int K; cin>>K;
    for(int i = 1; i < 10; i++){
        rec(1,i);
    }
    sort(RES.begin(),RES.end());
    cout<<RES.at(K-1)<<endl;
}

