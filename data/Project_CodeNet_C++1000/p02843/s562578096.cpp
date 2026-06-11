#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int x;
    cin>>x;
    int h=x/100;

    if(x>h*100+h*5) cout<<0<<"\n";
    else cout<<1<<"\n";
    return 0;
}