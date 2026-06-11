#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int b[(int)1e6+7]={},minfact[(int)1e6+7]={},Isprime[(int) 1e6+7]={},p[(int) 1e6+7]={};
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int algcd = a[0];
    for(int i=0;i<n;i++) algcd = gcd(algcd,a[i]);
    rep(i,1e6+8) Isprime[i] = 1;
    Isprime[0] = 0; Isprime[1] = 0;
    for(int i=2;i<=1e6+7;i++){
        if(Isprime[i]){
            minfact[i] = i;
            for(int j=2*i;j<=1e6+7;j+=i){
                if(minfact[j]!=0) continue;
                    minfact[j] = i;
                    Isprime[j] = 0;
            }
        }
    }
    int flag = 1;
    rep(i,n){
        map<int,int> res;
        while(a[i]>1){
            res[minfact[a[i]]]++;
            a[i] /= minfact[a[i]];
        }
        for(auto j:res){
            if(p[j.first]) flag = 0;
            else p[j.first] = 1;
        }
    }
    if(flag) cout << "pairwise coprime" << endl;
    else{
        if(algcd==1) cout << "setwise coprime"<< endl; 
        else cout << "not coprime" << endl;
    }
}