#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,flag=3;
    string s;
    cin>>s;
    int len=s.size();
    for(i=0,j=len-1;i<j;i++,j--){
        if(s[i]!=s[j])
        flag--;
    }
    for(i=0,j=(len-1)/2-1;i<j;i++,j--){
        if(s[i]!=s[j])
        flag--;
    }
    for(i=(len+1)/2,j=len-1;i<j;i++,j--){
        if(s[i]!=s[j])
        flag--;
    }
    if(flag==3)
    cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
    
}