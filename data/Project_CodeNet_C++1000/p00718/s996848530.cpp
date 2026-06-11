#include<bits/stdc++.h>

using namespace std;

int sm(const string &s){
    int n=s.length(),buf=1,res=0;
    for(int i=0;i<n;++i){
        if(s[i]>='0' && s[i]<='9'){
            buf=s[i]-'0';
            continue;
        }
        else if(s[i]=='m')res+=1000*buf;
        else if(s[i]=='c')res+=100*buf;
        else if(s[i]=='x')res+=10*buf;
        else if(s[i]=='i')res+=buf;
        buf=1;
    }
    return res;
}

string ms(int n){
    string res;
    int m,c,x,i;
    m=n/1000;
    n-=m*1000;
    c=n/100;
    n-=c*100;
    x=n/10;
    n-=x*10;
    i=n;
    if(m>=1){
        if(m>1)res+='0'+m;
        res+='m';
    }
    if(c>=1){
        if(c>1)res+='0'+c;
        res+='c';
    }
    if(x>=1){
        if(x>1)res+='0'+x;
        res+='x';
    }
    if(i>=1){
        if(i>1)res+='0'+i;
        res+='i';
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string s1,s2;
        cin>>s1>>s2;
        cout<<ms(sm(s1)+sm(s2))<<endl;
    }
}