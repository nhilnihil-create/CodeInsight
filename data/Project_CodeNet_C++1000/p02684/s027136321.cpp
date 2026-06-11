#include <bits/stdc++.h>
#define rep(i,l,r) for(int (i)=(l);(i)<(r);(i)++)
#define ll long long
using namespace std;
void deb(){
    cout<<"a";
    exit(0);
}
int main(){
    ll n,k;
    cin>>n>>k;
    vector<int> a(n),vi(n,-1);
    rep(i,0,n){
        cin>>a[i];
        a[i]--;
    }
    
    int cur=0;ll cnt=0;
    while(1){
        if(vi[cur]!=-1||k==cnt)break;
        vi[cur]=cnt;
        cur=a[cur];
        cnt++;
    }
    if(k>cnt){
        k-=vi[cur];
        cnt-=vi[cur];
        k%=cnt;
        rep(i,0,k)cur=a[cur];
    }
    cout<<cur+1<<endl;
}