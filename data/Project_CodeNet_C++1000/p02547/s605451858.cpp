#include<bits/stdc++.h>
using namespace std;

int main(){
    int num=0;
    int n;
    cin>>n;
    bool flag=false;
    for(int i=0; i<n; ++i){
        int x,y;
        cin>>x>>y;
        if(x==y) ++num;
        else num=0;
        if(num==3) flag=true;
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
}