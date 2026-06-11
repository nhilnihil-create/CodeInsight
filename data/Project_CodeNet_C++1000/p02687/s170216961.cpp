#include<iostream>
#include<math.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    if(s[1]=='B'){s[1]='R'; cout<<s;return 0;}
    else if(s[1]=='R'){s[1]='B';cout<<s;return 0;}
    return 0;
}
