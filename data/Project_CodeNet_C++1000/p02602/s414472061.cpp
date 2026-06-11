#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define p push_back
#define endl "\n"
#define l long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    l n,k,c=0,ans=1,ml=1,j=0;
    cin>>n>>k;
    vector<l>a;
    for(l i=0;i<n;i++){
        l s;
        cin>>s;
        a.p(s);
    }
    for(l i=k;i<n;i++){
        if(a[i]>a[i-k]){
            cout<<"Yes \n";
        }
        else cout<<"No \n";
    }
    return 0;
}
