#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(ll i=x;i<y;i++)

int main(){
    int a,b;
    cin>>a>>b;
    a=a-1, b=b-1;
    cout<<(b+a-1)/a<<endl;
}