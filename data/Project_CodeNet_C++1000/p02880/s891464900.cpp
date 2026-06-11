#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<=9)
        cout<<"Yes"<<endl;
    else if((n%2)==0&&(n/2<=9))
    {
            cout<<"Yes"<<endl;
    }
    else if((n%3)==0&&(n/3<=9))
    {
            cout<<"Yes"<<endl;
    }
    else if((n%4)==0&&(n/4<=9))
    {
            cout<<"Yes"<<endl;
    }
    else if((n%5)==0&&(n/5<=9))
    {
            cout<<"Yes"<<endl;
    }
    else if((n%6)==0&&(n/6<=9))
    {
            cout<<"Yes"<<endl;
    }
    else if((n%7)==0&&(n/7<=9))
    {
            cout<<"Yes"<<endl;
    }
    else if((n%8)==0&&(n/8<=9))
    {
            cout<<"Yes"<<endl;
    }
    else if((n%9)==0&&(n/9<=9))
    {
            cout<<"Yes"<<endl;
    }

    else
        cout<<"No"<<endl;


}
