#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s1[15],s2[15];
    int a,b;
    cin>>a>>b;
    int j=0;
    while(j<a){
        s1[j]=b+'0';
        j++;
    }
    s1[j]='\0';
     j=0;
    while(j<b){
        s2[j]=a+'0';
        j++;
    }
    s2[j]='\0';
    int d=strcmp(s1,s2);
    if(d>=0){
        j=0;
    while(j<b){
        cout<<s2[j];
        j++;
    }
}
else{
    j=0;
    while(j<a){
        cout<<s1[j];
        j++;
    }
}
   return 0;
}
