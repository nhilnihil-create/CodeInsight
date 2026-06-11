#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,a[100001],b[100001],i=1,j,saidai=0,m=0;
  
    cin >> n;
  
    for(i=0;i<n+1;i++)
    {
        cin >> a[i];
        saidai+=a[i];
    }
  
    for(i=0;i<n;i++)
    {
        cin >> b[i];
    }
  
    for(i=0;i<n;i++)
    {
        if(a[i]<b[i])
        {
            a[i+1] -= (b[i]-a[i]);
            if(a[i+1]<0)
            {
                a[i+1]=0;
            }
            a[i]=0;
        }
        else
        {
            a[i] -= b[i];
        }
    }
  
    for(i=0;i<n+1;i++)
    {
            m+=a[i];
    }

    cout << saidai-m << endl;
    
    
    
    return 0;

}
