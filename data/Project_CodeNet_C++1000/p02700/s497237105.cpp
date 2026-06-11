#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    int f=0;
    cin>>a>>b>>c>>d;
    while(1){
        if(f==0){
            c=c-b;
            f=1;
            if(c<=0){
                cout<<"Yes";
                break;
            }
        }
        if(f==1){
            a=a-d;
            f=0;
            if(a<=0){
                cout<<"No";
                break;
            }
        }
    }
}