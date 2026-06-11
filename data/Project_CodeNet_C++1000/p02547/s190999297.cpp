#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define m 1000000007
using namespace std;
int main()
{
    int t;
    t=1;
    while(t--)
    {
        int n,count=0,flag=0;
        cin >> n;
        while(n--)
        {
            int d1,d2;
            cin >> d1 >> d2;
            if(d1==d2)
            {
                count++;
            }
            else
            {
                count=0;
            }
            if(count==3)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
    }
	return 0;
}