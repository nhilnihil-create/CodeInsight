#include <bits/stdc++.h>
#define ep emplace_back
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>

typedef long long ll;

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    if (k<=a){
        cout << k << endl;
    }else if(k<=a+b){
        cout << a << endl;
    }else cout << a - (k-a-b);
    return 0;
}
