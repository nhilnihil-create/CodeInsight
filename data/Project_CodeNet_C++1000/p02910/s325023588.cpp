#include<bits/stdc++.h>
using namespace std;
int main(){
    int flag=0,i;
    string s;
    cin>>s;
    for(i=0;s[i]!='\0';i++){
        if(i%2==0){
            if(!(s[i]=='R' || s[i]=='U' || s[i]=='D'))
            {   flag++;
                break;
            }
        }
        else
        {
            if(!(s[i]=='U' || s[i]=='L'|| s[i]=='D' ))
            {
                flag++;
                break;
            }
        }
        
    }
    if(flag==0)
    cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
    
}