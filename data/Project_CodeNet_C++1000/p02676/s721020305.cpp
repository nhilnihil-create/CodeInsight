#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    //cout<<s.size()<<endl;
    if(s.size()>n){
        string k= s.substr(0,n);
        cout<<k<<"...";
    } else cout<<s;
    return 0;
}
