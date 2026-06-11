


#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x;
    cin>>x;
   long long sum=100;
    long long y=0;
    while(x>sum)
    {
        sum = sum + (sum / 100);
        y++;

    }

    cout<<y;



}
