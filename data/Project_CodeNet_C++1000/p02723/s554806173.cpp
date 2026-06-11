#include <bits/stdc++.h>
#include <string>
using namespace std;

char a,b,c,d;
string s;


int main(){
    cin>>s;
    a=s[2];
    b=s[3];
    c=s[4];
    d=s[5];
    if((a==b) && (c==d)){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
}