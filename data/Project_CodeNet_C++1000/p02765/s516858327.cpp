#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+233;

int t,n,r;
int main(){
    cin>>n>>r;
    if(n<10)cout<<(10-n)*100+r<<endl;
    else cout<<r<<endl;
    return 0;
}