#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    if(s[1]!=s[0]){
        if(s[2]!=s[0]){
            if(s[3]==s[0]&&s[2]==s[1]){printf("Yes");}
            else{printf("No");}
        }
        else{
            if(s[1]==s[3]){printf("Yes");}
            else{printf("No");}
        }
    }
    else if(s[2]!=s[0]){
        if(s[2]==s[3]){printf("Yes");}
        else{printf("No");}
    }
    else{printf("No");}
    printf("\n");

}