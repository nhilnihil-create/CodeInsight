#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,i=0,j,c=0,h[100010],a[100010],b[100010],ans=1;
    string s[200010];                                
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> s[i];
    }
    sort(s,s+n);
    for(i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;

}
