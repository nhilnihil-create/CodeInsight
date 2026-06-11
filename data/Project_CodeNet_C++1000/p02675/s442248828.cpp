#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a;
    b=a%10;
    if(b==3)
    {
        cout<<"bon"<<endl;
    }
    else if(b==2||b==4||b==5||b==7||b==9)
    {
        cout<<"hon"<<endl;
    }
    else
    {
        cout<<"pon"<<endl;
    }
    return 0;
}
