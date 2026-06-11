#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int c=0;
    for(int i=2;i<=n;i++){
        if((s[i-1]=='B' && s[i-2]=='A')&& s[i]=='C'){
            c++;
        }
    }
    cout<<c;
}
