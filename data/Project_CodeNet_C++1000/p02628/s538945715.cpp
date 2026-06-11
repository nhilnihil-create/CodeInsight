#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int cmp(int a,int b){
    return a<b;
}

int main(){
    int n,k;cin>>n>>k;
    int niz[n];
    for(auto &a:niz)
        cin>>a;
    sort(niz,niz+n,cmp);
    ll rj=0;
    for(int i=0;i<k;i++){
        rj+=niz[i];
    }
    cout <<rj<<endl;
}
