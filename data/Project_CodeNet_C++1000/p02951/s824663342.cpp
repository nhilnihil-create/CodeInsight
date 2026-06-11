 /******************************************************************************

                         بسم الله الرحمن الرحيم
                     Author: Mst: Mhamuda Khatun
                               RUCSE27

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 1000000007
#define MAX 1000000000000
#define N 305

int main()
{
    fastio;
    int a,b,c;
    cin>>a>>b>>c;

    if(c-(a-b)<0)
        cout<<0;
    else
        cout<<c-(a-b);

    cout<<"\n";
    return 0;   //:D
}


