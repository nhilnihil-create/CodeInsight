#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
const int mod=1e9+7;
int a[maxn];
main(){
    int n;
    cin>>n;
    int tmp=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        tmp^=a[i];
    }
    for(int i=1;i<=n;++i)cout<<(a[i]^tmp)<<" ";
    cout<<endl;
}
