#include<bits/stdc++.h>
using namespace std;
int main(){
    int flag=0,i;
    string s,t;
    cin>>s>>t;
    if(t.size()==s.size()+1)
    {
        for(i=0;i<t.size()-1;i++)
        {
            if(s[i]!=t[i])
            flag++;
        }
    }
    else
    {
        flag++;
    }
    if(flag==0)
    cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
    

}