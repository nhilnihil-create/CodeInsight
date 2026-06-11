#include <bits/stdc++.h>
using namespace std;
int main(void){
    [[maybe_unused]] long long int n,m,i=0,j,c=0,h[200010],a[200010],ans=0,saisyo=99999999,saidai=0;
    cin >> n;
    for(i=1;i<n;i++)
    {
        h[i]=0;
    }
    for(i=1;i<n;i++)
    {
        cin >> a[i];
        h[a[i]]++;
    }
    for(i=1;i<=n;i++)
    {
        cout << h[i] << endl;
    }
    
    return 0;

}
