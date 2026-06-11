#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,rm;
    cin>>n;
    rm=n%10;
    if(rm==3)
        cout<<"bon"<<endl;
    else if(rm==0 || rm==1 || rm==6 || rm==8)
        cout<<"pon"<<endl;
    else
        cout<<"hon"<<endl;
   return 0;
}
