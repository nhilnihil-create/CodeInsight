#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli h,a,cnt=0,i;
    cin>>h>>a;
    lli n[a];
    for(i=0;i<a;i++)
    cin>>n[i];
    for(i=0;i<a;i++)
    {
        h=h-n[i];
        cnt++;
    }
    if(h<=0)
    cout<<"Yes"<<"\n";
    else
    cout<<"No"<<"\n";
}