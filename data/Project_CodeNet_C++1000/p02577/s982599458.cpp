#include<bits/stdc++.h>

using namespace std;

char s[200005];

int main(){
    cin>>s+1;
    int n=strlen(s+1);

    int res=0;
    for(int i=1;i<=n;++i){
        res+=s[i]-'0';
    }

    if(res%9==0){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}
