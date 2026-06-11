#include<bits/stdc++.h>
#define PI 3.141592653589793238462
using namespace std;
typedef long long ll;
typedef long double db;
int main(){
    string s;cin>>s;
    if(s[s.length()-1]=='s'){
        cout<<s<<"es"<<endl;return 0;
    }
    else cout<<s<<"s"<<endl;
}