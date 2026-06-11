#include<iostream>
using namespace std;
int main()
{
    int n,l;
    cin>>n;
    l=n%10;
    if(l==2||l==4||l==5||l==7||l==9)
    {
        cout<<"hon"<<endl;
    }
    else if(l==0||l==1||l==6||l==8)
    {
        cout<<"pon"<<endl;
    }
    else
    {
        cout<<"bon"<<endl;
    }
    return 0;
}