#include<bits/stdc++.h>
using namespace std;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a,b,c,d=0;cin>>a>>b>>c;
while(true){
    a-=b;
    d+=c;
    if(a<=0)
        break;
}cout<<d<<endl;
return 0;}
