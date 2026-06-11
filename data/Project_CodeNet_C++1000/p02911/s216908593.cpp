#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> cnt(n);
    rep(i,q){
        int a;
        cin>>a;
        a--;
        cnt[a]++;
    }
    rep(i,n){
        if(k-q+cnt[i]>0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}