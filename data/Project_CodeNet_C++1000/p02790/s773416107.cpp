//Code by ASIM FOIZE AIMON
//CSE'19;CUET
//avoid copy paste//Hit the frined button
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define precise cout.precision(10); cout << fixed;
#define endl "\n"
#define int int64_t
#define ll long long
#define yes printf("YES\n")
#define no printf("NO\n")
#define push_back pb
int32_t main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("/media/AIMON/SSDVol/Progs/CodeForces/input.txt", "r", stdin);
        freopen("/media/AIMON/SSDVol/Progs/CodeForces/output.txt", "w", stdout);
    #endif*/
    long long a,b,c,d=0,e=0,i;
    cin>>a>>b;
    c=min(a,b);
    if(c==a)
    {
        for(i=0;i<b;i++)
        {
            cout<<c;
        }
        cout<<endl;
    }
    else
    {
       for(i=0;i<a;i++)
        {
            cout<<c;
        }
        cout<<endl;
    }
}
