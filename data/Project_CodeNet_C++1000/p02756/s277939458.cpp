#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    int q;
    cin>>q;
    int t,f;
    char c;
    bool rev=false;
    string front{}, back{};
    rep(i, q){
        cin>>t;
        if(t==1) {
            if(rev) rev=false;
            else rev=true;
            continue;
        }
        cin>>f>>c;
        if((f==1&&!rev)||(f==2&&rev)) front.push_back(c);
        else back.push_back(c);
    }
    reverse(front.begin(),front.end());
    s=front+s+back;
    if(rev){
        rep(i, s.size()/2){
            char tmp=s[i];
            s[i]=s[s.size()-1-i];
            s[s.size()-1-i]=tmp;
        }
    }
    cout<<s<<endl;
}