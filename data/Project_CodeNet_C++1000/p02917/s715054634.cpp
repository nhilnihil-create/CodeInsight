#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m,i=0,b[200000],ans=0;
    string s;
    cin >> n;
    for(i=1;i<n;i++)
    {
        cin >> b[i];
    }
    b[0]=100000000;
    b[n]=100000000;
    b[n+1]=100000000;
    for(i=1;i<n+1;i++)
    {
        ans+=min(b[i],b[i-1]);
    }
    cout << ans << endl;
    return 0;
}
