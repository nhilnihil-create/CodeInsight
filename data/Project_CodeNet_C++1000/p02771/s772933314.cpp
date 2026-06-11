#include <bits/stdc++.h>
using namespace std;
const int mod= 1e9+7;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define what_is(x) cerr << #x << " is " << x << endl;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    if (a==b && a==c)
        cout<<"No\n";
    else
    {
        if (a==b || a==c || b==c)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

}
