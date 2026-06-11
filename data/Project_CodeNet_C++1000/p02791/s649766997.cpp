#include<bits/stdc++.h>
 using namespace std;
const int N=2e5+20;
int n,a[N],mn=INT_MAX,x;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<mn) x++;
        mn=min(mn,a[i]);
    }
    cout<<x;
}
