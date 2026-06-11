#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n),cnt(1e6+10);
    for(auto &i:a) cin>>i;
    for(auto &i:cnt) i=0;
    
    //全体のGCDを取って2以上ならnot coprime
    int tmp = a[0];
    for(auto i:a){
        tmp = __gcd(tmp,i);
    }
    if(tmp>=2){
        cout<<"not coprime"<<endl;
        return 0;
    }

    //1を除き、同じ値があるならばsetwise coprime
    for(auto i:a){
        if(cnt[i]){
            cout<<"setwise coprime"<<endl;
            return 0;
        }
        if(i!=1){
            cnt[i]++;
        }
    }

    //因数について、その倍数が配列中に複数存在するならsetwise coprime
    for(int i=2; i<=1e6; i++){
        int c = 0;
        for(int j=1; j*i<1e6; j++){
            c += cnt[j*i];
        }
        if(c>1){
            cout<<"setwise coprime"<<endl;
            return 0;
        }
    }
    cout<<"pairwise coprime"<<endl;
}