#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,k,q,a,p[100005]={};
    cin>>n>>k>>q;
    for(int i=0;i<q;i++){
        cin>>a;
        p[a]++;
    }
    for(int i=1;i<=n;i++){
        if(q-p[i]>=k){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return(0);
}