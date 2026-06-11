#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a,b;
    cin>>a;
    cin>>b;
    char ara[1000000];
    char arb[1000000];
    int ia = a - '0';
    int ib = b - '0';
    for(int i=0;i<ia;i++){
        arb[i]=b;
    }
    for(int i=0;i<ib;i++){
    ara[i]=a;
    }

    if(strcmp(ara,arb)<=0){
               for(int i=0;i<ib;i++)
        cout<<ara[i];
    }
    else{
             for(int i=0;i<ia;i++){
        cout<<arb[i];

    }

    }


}
