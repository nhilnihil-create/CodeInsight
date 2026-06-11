#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    int f = 0;
    for(int i=0;i<=x;i++){
        int a = i;
        int b = x-i;
        if(a*2 + b*4 == y){ 
            f = 1;
            break;
        }
    }
    if(f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}