#include <bits/stdc++.h>

using namespace std;

int main()
{
    long x,y;
    cin>>x;
    y=x%10;
    if(y==2||y==4||y==5||y==7||y==9)
        cout<<"hon"<<endl;
    else if(y==0||y==1||y==6||y==8)
        cout<<"pon"<<endl;
    else if(y==3)
        cout<<"bon"<<endl;
    return 0;
}
