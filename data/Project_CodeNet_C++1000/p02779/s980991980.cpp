#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m,i=0,j,s,a[200010],min=1000000,goukei=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    a[n+1]=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    
    cout << "YES" << endl;
    return 0;

}
