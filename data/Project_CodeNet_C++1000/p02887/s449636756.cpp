#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m,i=0,j,p[200010],min=1000000,ans=0;
    string s;
    cin >> n >> s;
    ans=n;
    s=s+'A';
    for(i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
