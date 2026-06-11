#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, a[60], b[60];
int main()
{
    IO
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
                b[k]=a[k];
            swap(b[i],b[j]);
            if(is_sorted(b,b+n))
                return cout<<"YES", 0;

        }
    cout<<"NO";
}
