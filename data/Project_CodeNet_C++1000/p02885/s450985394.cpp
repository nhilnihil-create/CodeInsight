#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int a,b;
    cin>>a>>b;
    if(a<=b*2) cout<<0<<endl;
    else cout<<a-b*2<<endl;
}