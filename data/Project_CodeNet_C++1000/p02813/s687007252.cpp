#include<bits/stdc++.h>
using namespace std;

bool compare( int* a , int *b , int n )
{
    for(int i=0;i<n;i++)
    {
        if( a[i] != b[i] )
            return false;
    }
    return true;
}
int main()
{
    int n ;
    cin>>n;
    int p[n];
    int q[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    int a[n];
    for(int i=0;i<n;i++)
        a[i] = i+1;
    int t1 =0,t2=0;
    int count =0;
    while( next_permutation(a,a+n) )
    {
        count++;
        if( compare(a,p,n))
            t1 =count;
        if( compare(a,q,n))
            t2 = count;
    }
    cout<<abs( t1-t2);

}