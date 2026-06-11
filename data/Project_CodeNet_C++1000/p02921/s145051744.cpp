#include<bits/stdc++.h>
using namespace std;
int main(){

    string s,s1;
    cin>>s>>s1;
    int c=0;
    for(int i=0;i<s.size();i++){
        if(s.at(i)==s1.at(i)){
            c++;
        }
    }
    cout<<c<<endl;





}


