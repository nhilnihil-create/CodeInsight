#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
int A,B,m;
cin>>A>>B>>m;
int a[A],b[B];
int MA=INF,MB=INF;
rep(i,A){
    cin>>a[i];
    MA=min(MA,a[i]);
}
rep(i,B){
    cin>>b[i];
    MB=min(MB,b[i]);
}
int ans=MA+MB;

int x[m],y[m],c[m];
rep(i,m){
cin>>x[i]>>y[i]>>c[i];
}

rep(i,m){
    int price=a[x[i]-1]+b[y[i]-1]-c[i];
    ans=min(ans,price);
}
cout<<ans<<endl;
  return 0;
}
