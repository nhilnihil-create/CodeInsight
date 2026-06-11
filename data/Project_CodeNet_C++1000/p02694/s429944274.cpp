#include<bits/stdc++.h>
using namespace std;
#define    for0(i,n) for(int i=0;i<n;i++)
#define    fors(i,s) for(int i=0;i<s.size();i++)
#define    nl     "\n"
#define    End    return 0
#define    gt     greater<int>()
#define    ll     long long int

int main()
{
    ll n,p=100,c=0;
    cin>>n;
    while(p<n)
    {
        p+=(p/100);
        c++;
    }
    cout<<c;
}
