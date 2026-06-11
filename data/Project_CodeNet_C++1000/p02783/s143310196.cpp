#include<bits/stdc++.h>

typedef long long ll;
#define rep(i,n) for(int i=0,i<n;i++)
#define rept(i,n) for(int i=n,i>0;i--)
#define for(i,m,n) for(int i=m;i<n;i++)
#define all(v) v.bigin(),v.end()

using namespace std;

int main(){
    int h,a,n;
    cin>>h>>a;
    n=h/a;
    if(h%a!=0){
        n+=1;
    }
    cout<<n;
    return 0;
}

