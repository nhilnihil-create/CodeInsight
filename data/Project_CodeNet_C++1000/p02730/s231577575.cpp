#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(void){
    string s;
    cin>>s;
    
    string v=s,w=s.substr(0,(s.size()-1)/2),x=s.substr((s.size()+3)/2-1,(s.size()-3)/2+1),w2=w,x2=x;
    
    reverse(v.begin(),v.end());
    reverse(w2.begin(),w2.end());    
    reverse(x2.begin(),x2.end());
    
    if(s==v && w==w2 && x==x2) {
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }

    return 0;
}