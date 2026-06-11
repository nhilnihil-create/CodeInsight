#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,c;
    cin >> s;
    bool ok=true;
    for(int i=0;i<s.size();i++){
        if(s.at(i)!=s.at(s.size()-1-i))ok=false;
    }
    c=s;
    for(int i=0;i<s.size()/2+1;i++){
        c.pop_back();
    }
    for(int i=0;i<c.size();i++){
        if(c.at(i)!=c.at(c.size()-1-i))ok=false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}