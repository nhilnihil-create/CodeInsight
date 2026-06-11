#include <stdio.h>
#include <iostream>
using namespace std;

long long a[100010];
long long mask[61];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin >> n;
  
    for (int i=0;i<n;++i)
        cin >> a[i];

    long long ans=0;
    long long tmp=0;
    for (int i=0;i<n;++i)
        tmp^= a[i];

    ans=tmp;
    tmp= (1LL << 61)-1-tmp;
    //cout << tmp << endl;
    for (int i=0;i<n;++i)
        a[i]&=tmp;
    //cout << ans <<endl;
    tmp=0;
    for (int i=0;i<n;++i)
    {
        for (int j=60;j>=0;--j)
        {
            if ( (a[i]&(1LL<<j))==0 ) continue;
            if ( !mask[j] ){
                mask[j]=a[i];
                break;
            }
            a[i]^=mask[j];
        }
    }
    for (int i=59;i>=0;--i)
    {
       // cout << i << ' ' << mask[i] << tmp <<endl;
        if (mask[i] && (tmp^mask[i])>tmp)
            tmp^=mask[i];
          //cout << i << ' ' << mask[i] << tmp <<endl;
    }
    ans+=tmp*2;
    cout << ans <<endl;

}
