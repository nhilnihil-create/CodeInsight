#include <bits/stdc++.h>
#include <string>
using namespace std;

string s,t;
int a;


int main(){
    cin>>s>>t;
    a=t.length();
    t.erase(a-1,1);
    if(s==t){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
}