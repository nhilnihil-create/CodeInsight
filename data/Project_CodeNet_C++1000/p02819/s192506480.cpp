#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<iomanip>
#include<iterator>
#include<vector>
#include<map>
#include<utility>
#include<set>
#include<stack>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


    int x;
    cin>>x;
    for(;;)
    {
        int tmp=0;
        for(int i=2;i<=sqrt(x);i++)
        {
            if(x%i==0){tmp++;break;}
        }
        if(tmp==0)  {break;}
        else        {x++;}
    }
    cout<<x<<"\n";
    return 0;
}
