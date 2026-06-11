#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a;
    string s;
    cin>>s;
    string s1,s2;
    if(a%2==0){
        s1=s.substr(0,(a/2));
        s2=s.substr((a/2),a-1);
        if((s1==s2))  cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else{
       cout<<"No"<<endl;
    }

}
