#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000005
using namespace std;
ll n,a[MAXN],ch[3],ansch[2],cnt,ans;
char x;
bool bl1;
ll cnt2(ll i){
    ll ret=0;
    while(i%2==0){
        ret++;
        i/=2;
    }
    return ret;
}
int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>x;
        a[i]=x-'1';
        if (a[i]==1) bl1=1;
    }
    if (bl1){
        ch[0]=ch[2]=0;
        ch[1]=1;
        ansch[0]=0;
        ansch[1]=1;
    }
    else{
        ch[0]=0;
        ch[2]=1;
        ansch[0]=0;
        ansch[1]=2;
    }
    if (ch[a[0]]==1) ans=1;
    for (int i=1; i<n; i++){
        cnt+=cnt2(n-i)-cnt2(i);
        if (cnt==0 && ch[a[i]]==1) ans=1-ans;
        // cout<<cnt<<endl;
    }
    cout<<ansch[ans]<<endl;
}