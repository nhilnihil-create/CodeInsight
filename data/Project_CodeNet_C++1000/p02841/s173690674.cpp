#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    FASTINOUT;
    int m1,d1,m2,d2;
    cin>>m1>>d1>>m2>>d2;
    if ((m2==m1+1 ||(m1==12&&m2==1))&&(d2==1))
        cout<<1;
    else
        cout<<0;
    return 0;
}
