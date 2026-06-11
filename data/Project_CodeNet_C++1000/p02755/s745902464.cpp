#include<bits/stdc++.h>
using namespace std;

int binary( int a)
{
    int l =1;
    int r = 2000;
    while( l< r)
    {
        int mid = (l+r)/2;
        if( int(mid *0.08 )>= a)
        {
            r= mid;
            int temp = mid-1;
            if( int(temp*0.08) != a && int(mid*0.08) == a)
                return mid;
        } else
        {
            l = mid+1;
        }
    }
}

int binary2( int b)
{
    int l =1;
    int r = 2000;
    while( l< r)
    {
        int mid = (l+r)/2;
        if( int(mid *0.1) >= b)
        {
            r= mid;
            int temp = mid-1;
            if( int(temp*0.1) != b &&int( mid*0.1) == b)
                return mid;
        } else
        {
            l = mid+1;
        }
    }
}
int main()
{
    int a , b;
    cin>>a>>b;
    int ta = binary(a);
    int tb = binary2(b);
    int temp = max( ta , tb);

    if( int(temp*0.08) == a && int(temp*0.1) == b)
    {
        cout<<temp;
    }
    else cout<<-1;
}