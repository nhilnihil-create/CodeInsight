#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int x[1000] = {0},y[1000] = {0};
    double D1=0,D2=0,D3=0,D=0;

    for(int i = 0;i<n;i++)
    {
        cin>>x[i];
    }

    for(int i = 0;i<n;i++)
    {
        cin>>y[i];
    }

    for(int i = 0;i<n;i++)
    {
        D1 = D1 + pow(abs(x[i]-y[i]),1);
        D2 = D2 + pow(abs(x[i]-y[i]),2);
        D3 = D3 + pow(abs(x[i]-y[i]),3);

        if(D < abs(x[i] -y[i]))
        {
            D = abs(x[i] -y[i]);
        }
    }

    printf("%.6f\n",D1);
    printf("%.6f\n",pow(D2,(double)1/2));
    printf("%.6f\n",pow(D3,(double)1/3));
    printf("%.6f\n",D);

    return 0;
}