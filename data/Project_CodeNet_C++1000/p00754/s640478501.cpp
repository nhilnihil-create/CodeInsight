#include<bits/stdc++.h>
using namespace std;

bool isok(int f,int e,const string& s){
    if(f>=e)
        return true;
    int x=-1;
    for(int i=f;i<e;i++){
        if(s[i]=='(' || s[i]=='['){
            x=i;
            break;
        }
        if(s[i]==')' || s[i]==']')
            return false;

    }
    if(x==-1)
        return true;

    char rig;
    if(s[x]=='(')
        rig=')';
    else
        rig=']';
    int y=-1;
    int cnl=1;int cnr=0;
    for(int i=x+1;i<e;i++){
        if(s[i]==rig)cnr++;
        if(s[i]==s[x])cnl++;
        if(cnr==cnl){
            y=i;
            break;
        }


    }
    if(y==-1)
        return false;
    return isok(x+1,y,s) && isok(y+1,e,s);
}
int main(){
    string s;
    while(getline(cin,s),s!="."){
        string res=(isok(0,s.size(),s) ? "yes":"no");
        cout<<res<<endl;

    }
    return 0;
}