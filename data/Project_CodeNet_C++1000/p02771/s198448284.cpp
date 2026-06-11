#include <iostream>
#include<string>
 using namespace std;
 
 int main(){
     int a, b, c;
     cin>>a>>b>>c;
 
 
    if(a==c && b!=c){cout<<"Yes";}
    else if(a==b && c!=b){cout<<"Yes";}
    else if(b==c && a!=c){cout<<"Yes";}
     else {cout<<"No";}
     }