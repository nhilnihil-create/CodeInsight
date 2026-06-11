#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define d 1000000007
using namespace std;
int main()
{
    int t;
    t=1;
    while(t--)
    {
        int n;
        cin >> n;
        ll total=0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j*i<n;j++)
            {
                total++;
            }
        }
        cout << total;
    }
	return 0;
}