#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
#define rep(i,s,e) for(int i=s;i<e;i++)
int main(){
    int n;cin>>n;
    int A[n+1];
    rep(i,0,n+1)A[i]=0;
    rep(i,0,n-1){
        int a;cin>>a;
        A[a]++;
    };
    rep(i,1,n+1){
        cout<<A[i]<<endl;
    }

}
