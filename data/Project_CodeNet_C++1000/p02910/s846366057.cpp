#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
long long i,p=0,r=0;
for(i=0;i<s.size();i++){
    if(i%2==0){
        if(s[i]!='R'&&s[i]!='U'&&s[i]!='D'){
            p=1;break;
        }
        
    }else{
        if(s[i]!='L'&&s[i]!='U'&&s[i]!='D'){
            r=1;break;
        }
    }
}if(p==1||r==1)
cout<<"No";
else
cout<<"Yes";

    return 0;
}
