#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n),cnt(1e6+10);
    for(auto &i:a) cin>>i;
    for(auto &i:cnt) i=0;

    bool s=false,nt=false;

    int tmp = a[0];
    for(auto &i:a){
        tmp = __gcd(i,tmp);
    }
    if(tmp>=2) nt=true;

    for(auto &i:a){
        if(cnt[i]) s=true;
        if(i!=1){
            cnt[i]++;
        }
    }
    
    for(int i=2; i<1e6+10; i++){
        int c = 0;
        for(int j=1; j*i<1e6+10; j++){
            c += cnt[j*i];
        }
        if(c>1) s=true;
    }

    if(nt) cout<<"not coprime";
    else if(s) cout<<"setwise coprime";
    else cout<<"pairwise coprime";
    cout<<endl;
}