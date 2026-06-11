#include<bits/stdc++.h>
using namespace std;

int binary( int n )
{
    int l =1;
    int r = 50000;
    while( l<r)
    {
        int mid= (l+r)/2;
        if( int(mid* 1.08) > n)
        {
            r= mid;
        }
        if( int(mid*1.08) < n)
        {
            l = mid+1;
        }
        if( int(mid*1.08)== n)
            return mid;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int ans = binary(n);
    if( ans==0)
        cout<<":(";
    else cout<<ans;

}