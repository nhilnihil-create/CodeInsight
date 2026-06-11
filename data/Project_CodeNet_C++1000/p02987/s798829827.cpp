#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    
    int count = 0;
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s.size(); j++){
            if(s[i]==s[j]) count++;
        }
    }
    
    if(count==8) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}