#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int k,i,l;
    string s;
    cin>>k;
    cin>>s;
    l=s.length();
    if(l<=k){
        for(i=0;i<l;i++)
        cout<<s[i];
    }
    else{
         for(i=0;i<k;i++)
        cout<<s[i];
        cout<<"...";
    }
}
