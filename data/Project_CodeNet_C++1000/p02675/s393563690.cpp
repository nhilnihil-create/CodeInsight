#include<bits/stdc++.h>

using namespace std;



int main(){
int n;
do{

    cin>>n;
}while(n<0||n>999);
int a=n%10;
{
    if(a==2||a==4||a==5||a==7||a==9)
    {
        cout<<"hon";
    }
    if(a==0||a==1||a==6||a==8)
    {
        cout<<"pon";
    }
    if(a==3)
    cout<<"bon";
}
return 0;
}
