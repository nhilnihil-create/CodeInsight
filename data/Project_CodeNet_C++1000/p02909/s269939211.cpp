#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    getline(cin,a);
    if(a[0]=='S') printf("Cloudy");
    else if(a[0]=='C') printf("Rainy");
    else if(a[0]=='R') printf("Sunny");
    return 0;
}
