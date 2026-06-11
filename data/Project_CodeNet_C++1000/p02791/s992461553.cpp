#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m,i=0,j,s=10000000,p[200010],min=1000000,ans=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> p[i];
    }
    for(i=0;i<n;i++)
    {
        if(s>p[i])
        {
            s=p[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;

}
