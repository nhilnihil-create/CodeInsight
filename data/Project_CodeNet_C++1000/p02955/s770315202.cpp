#include<bits/stdc++.h>
using namespace std;
int a[1000], b[1000];
long long int n, k, sum=0;
long long int y, z=0, m=1, t=0;

int fun(int i)
{

    for(int j=0; j<n; j++)
    {
        if(a[j]%i!=0)
        {
            b[z++]=a[j]%i;
            // cout << b[z-1]<< " ";
        }
    }
    sort(b, b+z);

    int l=0, r=z-1;
    // cout << i;
    while(l<r)
    {
        if(b[l]%i==0)
        {
            l++;
            continue;
        }
        if(b[r]%i==0)
        {
            r--;
            continue;
        }
        long long int u=min(b[l]%i, i-b[r]%i);

        //cout << b[l]  << "   " << b[r] <<"   " <<u<< " "<<i << endl;
        b[l]-=u;
        b[r]+=u;
        y+=u;
        //cout << "    " << u;
        if(y>k)
        {
              y=0,m=1, z=0;
            return 0;
        }
    }
      y=0,m=1, z=0;
    return 1;
}

int main()
{

    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sum+=a[i];
    }

    for(long long int i=1; i*i<=sum; i++)
    {
        y=0,m=1, z=0;
        if(sum%i==0)
        {

            if(fun(sum/i))
            {
                cout << sum/i ;
                return 0;
            }
            else if(fun(i))
            {

                t=max(t, i);
            }
        }
    }
    cout << t;
    return 0;
}
