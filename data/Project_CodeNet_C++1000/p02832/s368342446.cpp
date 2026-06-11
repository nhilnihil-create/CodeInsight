#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    int cnt=0;
    bool flag=true;
    int i=0;
    int j=1;
    while(i<n){
        while(i<n){
            if(a[i]!=j) cnt++;
            else{
                i++;
                break;
            }
            i++;
        }
        j++;
    }
    if(cnt!=n) cout<<cnt<<"\n";
    else cout<<-1<<"\n";
    return 0;
}