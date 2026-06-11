#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    int n;
    ll h=0;
    cin>>n;
    int a[n];
    for (int i = 0; i<n; i++)
        cin>>a[i];

    for ( int i=1; i<n; i++ )
        if ( a[i] - a[i-1] < 0)
            {
                int diff = a[i-1] - a[i] ;
                a[i] += diff;
                h += diff;
            }

    cout<<h<<endl;
}