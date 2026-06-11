#include<bits/stdc++.h>

using namespace std;

int main(){
    string s,c;
    int n,i,j,k;
    cin>>n>>s;
    int len=s.size();
    for(i=0;i<len;i++){
        if(s[i]+n>'Z'){cout<<char(s[i]+n-26);}
        else {cout<<char(s[i]+n);}
    }

    return 0;
}
