#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000000
#define ll long long int
//ll a[40001000];
//ll number[20],used[20];
int main()
{
    string a,b,c;
    cin >> a;
    if(a[0]=='S')
        cout << "Cloudy" << endl;
    else if(a[0]=='R')
        cout << "Sunny" << endl;
    else if(a[0]=='C')
        cout << "Rainy" << endl;
    return 0;
}
