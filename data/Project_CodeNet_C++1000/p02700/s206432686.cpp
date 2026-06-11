#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int t=0;
    int o=0;
    while(c>0){
        c-=b;
        t++;
    }
    while(a>0){
    a-=d;
    o++;
    }
    if(t<=o) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}