#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    bool OK=true;
    for(int i=0;i<s.length();i++){
        if(i%2==0) if(s[i]!='R'&&s[i]!='U'&&s[i]!='D') OK=false;
        if(i%2==1) if(s[i]!='L'&&s[i]!='U'&&s[i]!='D') OK=false;
    }
    if(OK) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
} 