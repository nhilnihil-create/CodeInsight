#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;

/// Info.
///****************************************************************************************************************************************///
/// author                : BAHAA El-DEEN OSAMA .
/// Problem name          : E - An Odd Problem
/// Method                : brute force
/// Online judge          : vjudge(Contest)
/// Date                  : 8/6/2020
///****************************************************************************************************************************************///

long long val,n,cnt=0;

int main()
{

    cin>>n;
    for(int i=0 ;i<n;++i)
    {
         cin>>val;
         if( (val&1) && ((i+1)&1) )
         {
             ++cnt;
         }
    }
    cout <<cnt<<endl;



return 0;
}
