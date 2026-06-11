#include<bits/stdc++.h>
using namespace std;

int main(){

int a,b;
string s,t,u;

cin>>s;
cin>>t;
cin>>a;
cin>>b;
cin>>u;

    if(s==u)
        a=a-1;
    else if(t==u)
        b=b-1;

cout<<a<<" "<<b;

    return 0;


}