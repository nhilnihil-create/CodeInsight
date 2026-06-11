#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ud=n%10;;

    if(ud == 2||ud==4||ud==5||ud==7||ud==9)
        cout<<"hon";
    else if(ud==0||ud==1||ud==6||ud==8)
        cout<<"pon";
    else
        cout<<"bon";
}
