#include <bits/stdc++.h>

using namespace std;

int main() {

    char a,b;
    cin>>a>>b;
    int x = a-'0',y=b-'0';
    string res1="",res2="";
    while(x--){
        res1+=b;
    }
    while(y--){
        res2+=a;
    }

    if(res1<=res2)cout<<res1<<endl;
    else cout<<res2<<endl;


    return 0;
}
