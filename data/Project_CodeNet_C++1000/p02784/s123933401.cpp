#include<bits/stdc++.h>

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rept(i,n) for(int i=n;i>0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(v) v.bigin(),v.end()

using namespace std;

int main(){
    int h,n;
    
    cin>>h>>n;
    int a[n];
    rep(i,n){
        cin>>a[i];
        h-=a[i];
        }
    if(h<=0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}


