#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
const int maxn = 1e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    int a , b;  cin  >> a>> b;
    int ans = 0;
    while (a){
        a /= b;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
