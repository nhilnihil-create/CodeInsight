#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long num,solve;
    while(cin>>num)
    {
        int count=0;
        solve=100;
        while(num>solve)
        {
            solve=solve+(solve/100);
            count++;
        }
        cout<<count<<endl;
        break;
    }
}
