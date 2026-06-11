
#include <iostream>
#include <cstring>
//#include <bits/stdc++.h>
using namespace std;
int main(){
    //char a[200000];
    string a;
    cin>>a;
    int b=a.length();
    //b=strlen(a);
    //cout<<b<<endl;
    for(int i=0;i<b;i++){
        if(a[i]=='?'){
            /*if(a[i-1]=='P'){
                a[i]='D';
            }
            if(a[i-1]=='D'){
                /*if(a[i+1]=='D'||a[i+1]=='?'){
                    a[i]='P';
                }else{
                    a[i]='D';
                }
                a[i]='D';
            }*/
            a[i]='D';
        }
    }
    cout<<a<<endl;
}
