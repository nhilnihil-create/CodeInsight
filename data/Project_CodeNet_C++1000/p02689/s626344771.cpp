#include <bits/stdc++.h>
using namespace std;
int main(void){
    [[maybe_unused]] long long int n,m,i,j,c=0,h[1000010],a[1000010],b[1000010],x[1000010],ans=0;
    cin >> n >> m;
    for(i=0;i<n;i++)
    {
        cin >> h[i];
        x[i]=0;
    }
    for(i=0;i<m;i++)
    {
        cin >> a[i] >> b[i];
        if(h[a[i]-1]>h[b[i]-1])
        {
            x[b[i]-1]++;
        }
        else if(h[a[i]-1]<h[b[i]-1])
        {
            x[a[i]-1]++;
        }        
        else
        {
            x[a[i]-1]++;
            x[b[i]-1]++;
        }
    }
    for(i=0;i<n;i++)
    {
        if(x[i]==0)
        {
            ans++;
        }
    }
    cout << ans << endl;
 
    return 0;

}
