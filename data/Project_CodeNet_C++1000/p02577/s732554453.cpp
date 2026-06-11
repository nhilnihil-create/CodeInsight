#include <iostream>
#include <bits/stdc++.h>

using namespace std;
char s[200010];
int main()
{
    cin>>s;
    int len=strlen(s);
    int sum =0;
    for(int i = 0;i<len;i++){
        sum+=s[i]-'0';
    }
    if(sum %9 == 0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}
