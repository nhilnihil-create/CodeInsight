#include <bits/stdc++.h>
using namespace std;

int main(){
    char S[11],T[12];
    cin>>S>>T;
    int ans=1;
    for(int i=0;i<strlen(S);i++){
        if(S[i]!=T[i]){printf("No\n");return 0;}
    }
    printf("Yes\n");
} 