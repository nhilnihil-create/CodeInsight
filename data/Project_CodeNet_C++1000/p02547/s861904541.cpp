#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
const ll inf=2e18;
const int mod=998244353;
int n;
bool a[102];
int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(x==y)a[i]=1;
    }
    bool f=0;
    for(int i=1;i<=n-2;i++){
        if(a[i]&&a[i+1]&&a[i+2])f=1;
    }
    if(f)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
