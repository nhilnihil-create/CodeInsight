#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m,i=0,h[200000],ans=0,c=0;
    string s;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> h[i];
    }
    h[n]=100000000010;
    for(i=0;i<n;i++)
    {
        if(h[i]>=h[i+1])
        {
            c++;
            if(ans<c)
            {
                ans=c;
            }
            continue;
        }
        c=0;
    }
    cout << ans << endl;
    return 0;
}
