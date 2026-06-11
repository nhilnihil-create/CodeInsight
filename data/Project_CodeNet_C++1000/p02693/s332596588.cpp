#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A,B,k,i,count=0;
    cin >> k >> A >>B;
    for(i=A;i<=B;i++)
    {
       if(i%k==0)
        count=1;
    }
    if(count==1)
    {
        cout << "OK";
    }
    else
    {
        cout << "NG";
    }

}
