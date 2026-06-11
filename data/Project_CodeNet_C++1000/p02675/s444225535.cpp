#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int check = n%10;
    if(check==2||check==4||check==5||check==7||check==9)
    {
        cout<<"hon";
    }
    else if(check==0||check==1||check==6||check==8)
    {
        cout<<"pon";
    }
    else
    {
        cout<<"bon";
    }
}
