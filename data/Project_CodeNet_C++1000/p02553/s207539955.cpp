#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c,d,p1,p2,p3,p4,ans,mx1,mx2;
    cin >> a >> b >> c >> d;
    p1=a*c;
    p2=a*d;
    p3=b*c;
    p4=b*d;
    mx1 = max(p1,p2);
    mx2 = max(p3,p4);

    ans = max(mx1,mx2);
    cout << ans << endl;

    return 0;
}