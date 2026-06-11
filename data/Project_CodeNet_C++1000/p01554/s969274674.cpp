#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,d=0,r;
    string key[257],s[2]={"Opened by ","Closed by "},in;
    for(cin>>a;a>0;a--)cin>>key[a];
    for(cin>>b;b>0;b--){
        cin>>in;
        r=1;
        for(int j=1;j<257;j++)if(key[j]==in){
            cout<<s[d]<<in<<endl;
            d=++d%2;
            r=0;
        }
        if(r)cout<<"Unknown "<<in<<endl;
    }
}