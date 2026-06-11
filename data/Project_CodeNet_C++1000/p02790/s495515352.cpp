#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<math.h>
#include<cstring>
using namespace std;
void lets_play()

{

    int a,b,i;
    cin>>a>>b;
    if(a>=b)
    {
        for(i=1;i<=a;i++)
            cout<<b;
        cout<<endl;
    }
    else
    {
        for(i=1;i<=b;i++)
            cout<<a;
        cout<<endl;
    }
    }

int main()
{
        lets_play();

}
