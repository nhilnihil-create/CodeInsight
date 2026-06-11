#include<bits/stdc++.h>
using namespace std;
int main()
{
    string strc,strd,stra,strb;
    int a,b,i;
    cin>> a >> b;
    stra=a+48;
    strb=b+48;
    for(i=1;i<=a;i++)
        strc=strc+strb;
    for(i=1;i<=b;i++)
        strd=strd+stra;
    if(strc==strd)
        cout<< strc<<endl;
    else
        cout << min(strc,strd)<<endl;;
    return 0;
}
