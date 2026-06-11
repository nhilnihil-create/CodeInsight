#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b;
    cin>>a>>b;

    int n=0;
    int cnt=1;

    while(cnt<b)
    {
        cnt+=a-1;
        n++;
    }

    cout<<n<<"\n";

    return 0;
}
