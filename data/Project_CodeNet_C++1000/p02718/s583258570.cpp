#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, i, count=0, q=0;float t;
    cin>>n>>m;
    int a[n];
    for(i = 0; i<n; i++) cin>>a[i];
    for(i = 0; i<n; i++){q=q+a[i];};t = ((1.0/(4*m))*q);
    for(i = 0; i<n; i++)
    {
        if(a[i]>=t)
        {
            count++;
        }
    }
    if(count>=m)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
