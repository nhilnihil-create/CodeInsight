#include <bits/stdc++.h> 
using namespace std;
int main() {
string s;
int res=0,count=0;
cin>>s;
for(int i=0;i<=s.size();i=i+2){
    if(s[i]=='L'){
        count++;
    }
}
for(int i=1;i<=s.size();i=i+2){
    if(s[i]=='R'){
        res++;
    }
}
if(count==0 && res==0){
    cout<<"Yes"<<endl;
}
else
cout<<"No"<<endl;


return 0;
}