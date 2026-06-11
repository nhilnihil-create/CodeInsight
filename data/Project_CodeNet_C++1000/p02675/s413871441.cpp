#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s;
    s=n%10;

        if(s==3)
        {
        cout<<"bon"<<endl;
        }
        else if(s==0||s==1||s==6||s==8)
        {
        cout<<"pon"<<endl;
        }
        else if(s==2||s==4||s==5||s==7||s==9)
        {
        cout<<"hon"<<endl;
        }


    return 0;

}
