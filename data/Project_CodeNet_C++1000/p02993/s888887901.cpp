#include<iostream>
#include<math.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i=3;i>-1;i--){
        if(s[i]==s[i-1]){cout<<"Bad"; return 0;}
    }
    cout<<"Good";
}
