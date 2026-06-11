#include <bits/stdc++.h>
using namespace std;
int main(){

    string s;
    bool special=true;
    cin>>s;
    for (int i=0;i<4;i++){
        if(count(s.begin(),s.end(),s[i])!=2){
            special=false;
            break;
        }
    }
    if(special)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
