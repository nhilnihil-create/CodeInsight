#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    string s1;
    int a,b;
    cin>>s>>s1>>a>>b;
    string u;
    cin>>u;
    if(u==s){
        a--;
    }
    else b--;
    cout<<a<<" "<<b;
    
}
