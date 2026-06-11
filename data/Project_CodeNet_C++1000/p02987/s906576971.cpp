#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

string s;
cin>>s;
sort(s.begin(), s.end());
if (s[0]==s[1] && s[2]==s[3]){
    if (s[0]==s[2]){
        cout<<"No";

    }
    else{
        cout<<"Yes";
    }
}
else{
    cout<<"No";
}



return 0;
}
