#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    int n,m,p;
    int ans;
    string s;
    string str;
    string c;
    vector<int>x;
    while(true) {
        s="";
        while(true){
            getline(cin,str);
            s+=str;
            if(str.back()!='.')s.push_back(' ');
            else break;
        }
        if(s.front()=='.')break;
        t=0;n=0;m=0;p=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){t++;c.push_back(s[i]);}
            if(s[i]==')'){
                n++;
                if(c.back()=='['){cout<<"no"<<endl;goto invail;}
                else if(c.size()>0)c.pop_back();
            }
            if(s[i]=='['){m++;c.push_back(s[i]);}
            if(s[i]==']'){
                p++;
                if(c.back()=='('){cout<<"no"<<endl;goto invail;}
                else if(c.size()>0)c.pop_back();
            }
            if(t<n){cout<<"no"<<endl;goto invail;}
            if(m<p){cout<<"no"<<endl;goto invail;}
        }
        if(t>n||m>p)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
        invail:;
    }
    return 0;
}
