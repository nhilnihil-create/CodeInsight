#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
    int a,b,i;
    cin>>a>>b;
    if(a>b)
        swap(a,b);
    for(i=1;i<=b;i++)
        cout<<a;
}