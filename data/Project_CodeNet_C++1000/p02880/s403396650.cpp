#include<iostream>
using namespace std;

int main()
{
    int i;
    cin>>i;
    if(i>=1||i<=100)
    {
   if(i%1==0&&(i/1>=1&&i/1<=9))
    cout<<"Yes";
   else if(i%2==0&&(i/2>=1&&i/2<=9))
    cout<<"Yes";
    else if(i%3==0&&(i/3>=1&&i/3<=9))
    cout<<"Yes";
    else if(i%4==0&&(i/4>=1&&i/4<=9))
    cout<<"Yes";
    else if(i%5==0&&(i/5>=1&&i/5<=9))
    cout<<"Yes";
    else if(i%6==0&&(i/6>=1&&i/6<=9))
    cout<<"Yes";
    else if(i%7==0&&(i/7>=1&&i/7<=9))
    cout<<"Yes";
    else if(i%8==0&&(i/8>=1&&i/8<=9))
    cout<<"Yes";
    else if(i%9==0&&(i/9>=1&&i/9<=9))
    cout<<"Yes";
     else
        cout<<"No";
    }
    return 0;
}
