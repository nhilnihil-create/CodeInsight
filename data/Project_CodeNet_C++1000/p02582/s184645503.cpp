#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s[1]=='R'){
        if(s[0]=='R'&& s[2]=='R'){
            printf("%d\n",3);
        }else if(s[0]=='R'|| s[2]=='R'){
            printf("%d\n",2);
        }else{
            printf("%d\n",1);
        }
    }else if(s[0]=='R' || s[2]=='R'){
        printf("%d\n",1);
    }else{
        printf("%d\n",0);
    }
}