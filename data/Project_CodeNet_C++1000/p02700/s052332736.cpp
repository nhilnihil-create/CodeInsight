#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c,d,takahashi=0,aoki=0;
cin>>a>>b>>c>>d;
while(a>0){
    a-=d;
    takahashi++;
}
while(c>0){
    c-=b;
    aoki++;
}
if(takahashi>=aoki) cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}
