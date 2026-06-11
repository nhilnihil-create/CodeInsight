#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    char a[12],b[12];
    for(int i=0; i<s2.length()-1; i++){
        b[i]=s2[i];
    }
    int fl=1;
    for(int i=0; i<s1.length(); i++){
        if(b[i]!=s1[i]){
            puts("No");
            fl=0;
            break;
        }
    }
    if(fl) puts("Yes");

}
