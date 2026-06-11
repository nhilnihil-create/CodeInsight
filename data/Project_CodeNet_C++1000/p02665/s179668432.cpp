#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[n+1], sum = 0;
    for(int i = 0; i <= n; i++) 
    {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 1;
    ll node = 1; // non leaf node at level i
    bool flag = false; 
    if(n == 0 && a[0] != 1 ) // root node is a leaf node
flag = true;
if(n != 0 && a[0] !=  0) // root node hase child
flag = true; 

for(int i = 1; i <= n; i++)
{
node = min(node*2, sum); // maximum node possible at level i
ans += node; 
if(node < a[i]) // if max possible node is greater than leaf nodes 
{
flag = true;
break;
}
node -= a[i];
sum -= a[i];

}
if(flag) ans = -1;
cout << ans;
}
