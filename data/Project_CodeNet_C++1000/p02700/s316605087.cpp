#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);

const int N = 2e5 + 5;

int32_t main()
{
    IOS;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int x = (a+d-1)/d;
    int y = (b+c-1)/b;
    if(x >= y)
        cout << "Yes\n";
    else
        cout << "No\n";
}

