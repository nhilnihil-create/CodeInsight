#include<bits/stdc++.h>
using namespace std;
string up = "QWERTYUIOPLKJHGFDSAZXCVBNM";
string down = "qwertyuioplkjhgfdsazxcvbnm";
signed main(){
    char x;
    cin>>x;
    for(int i=0;i<26;i++){
        if(x==up[i]){
            cout<<'A';
            return 0;
        }
        if(x==down[i]){
            cout<<'a';
            return 0;
        }
    }
}
