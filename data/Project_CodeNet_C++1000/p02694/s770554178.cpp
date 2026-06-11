#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a;
    long long sum=0,sum2=100;
    cin>>a;
    while (sum2 < a){
        sum2 += sum2/100;
        sum++;
    }
    cout << sum<<endl;

    return 0;
}