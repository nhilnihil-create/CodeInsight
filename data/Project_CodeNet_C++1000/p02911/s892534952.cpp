#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,k,q,a[100000],i,l[100000];
    cin >> n >> k >> q;
    for(i=0;i<q;i++)
    {
        cin >> a[i];
    }
    for(i=1;i<=n;i++)
    {
        l[i]=0;
    }
    for(i=0;i<q;i++)
    {
         {
             l[a[i]]+=1;
         }
    }
    for(i=1;i<=n;i++)
    {
        if(q-l[i]>=k)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}
