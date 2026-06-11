#include <bits/stdc++.h>
using namespace std;
string s,t;
bool flag=false;
int main(){
 cin>>s>>t;
 for(int i=0;i<s.size();i++){
    if(s[i]!=t[i]){
        flag=true;
        break;
    }
}
if(flag==true)cout<<"No";
else cout<<"Yes";


    return 0;}


