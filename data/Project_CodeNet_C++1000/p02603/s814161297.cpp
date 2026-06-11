#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+1000;
ll n,k,a[maxn],dif[maxn];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++) dif[i]=a[i]-a[i-1];
    ll mo=1000,num=0;
    for(int i=i;i<n;i++){
        if(dif[i]>0){
            num=floor(mo/a[i-1]);
            mo-=floor(mo/a[i-1])*a[i-1];
            mo+=num*a[i];
        }
    }
    cout<<mo<<endl;
    return 0;
}
