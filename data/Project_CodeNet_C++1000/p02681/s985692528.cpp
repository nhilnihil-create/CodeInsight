#include<bits/stdc++.h>
using namespace std;
int main(){
        string s,t; cin>>s>>t;
        int n1=s.length(),n2=t.length();
        if(n2!=(n1+1)) { cout<<"No"<<endl; return 0;}
        for(int i=0;i<n1;i++) if(s[i]!=t[i]) { cout<<"No"<<endl; return 0;}
        cout<<"Yes"<<endl;
        return 0;
}

