#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++);
using ll=long long;
int  main(){
string S;
cin>>S;
char a=S.at(0);
bool t=false;
if(a==S.at(1)&&S.at(2)!=a&&S.at(3)!=a){
    if(S.at(2)==S.at(3)){
        t=true;
    }
}
 else if(a==S.at(2)&&S.at(1)!=a&&S.at(3)!=a){
    if(S.at(1)==S.at(3)){
        t=true;
    }
}
else if(a==S.at(3)&&S.at(2)!=a&&S.at(1)!=a){
    if(S.at(1)==S.at(2)){
        t=true;
    }
}

if(t==false){
    cout<<"No"<<endl;
}
else
{
    cout<<"Yes"<<endl;
}

 }


