#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main()
{
    int m,d;
    cin >>m>>d;
    int ans =0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=d;j++){
            int c=j;
            int a=c%10;
            c/=10;
            int b=c%10;
            if(a>=2&&b>=2&&a*b==i)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
