#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli h,a,cnt=0;
    cin>>h>>a;
    while(h>0)
    {
        h=h-a;
        cnt++;
    }
    cout<<cnt<<"\n";
}