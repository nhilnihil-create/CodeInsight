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
int32_t main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("/media/AIMON/SSDVol/Progs/CodeForces/input.txt", "r", stdin);
        freopen("/media/AIMON/SSDVol/Progs/CodeForces/output.txt", "w", stdout);
    #endif*/
    long long n,i,j,k=0,l,x;
    cin>>n;
    x=n+1;
    for(i=0; i<n; i++)
    {
        cin>>j;
        if(j<x)
        {
            k++;
            x=j;
        }
    }
    cout<<k<<endl;
    return 0;
}

