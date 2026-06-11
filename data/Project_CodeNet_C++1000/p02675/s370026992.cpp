#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<10)
    {
        if(n==3)
        {
            cout<<"bon";
            return 0;
        }
        else if(n==2 || n==4 || n==5 || n==7 || n==9)
        {
            cout<<"hon";
            return 0;
        }
        else
        {
            cout<<"pon";
            return 0;
        }
    }
    else
    {
        n=n%10;
        if(n==3)
        {
            cout<<"bon";
            return 0;
        }
        else if(n==2 || n==4 || n==5 || n==7 || n==9)
        {
            cout<<"hon";
            return 0;
        }
        else
        {
            cout<<"pon";
            return 0;
        }
    }
}
