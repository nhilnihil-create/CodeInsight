#include<bits/stdc++.h>
#include<iostream>
#include<algorithm> 
#include<cstring>
#define ios ios::sync_with_stdio(false)
#define mem(arr) memset(arr,0,sizeof(arr))
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
ll a[maxn] = {0,0,0,1,1};
int main() 
{
	int n;
    cin>>n;
    for(int i = 4; i <= n; i++)
        a[i] = (a[i - 1] + a[i - 3]) % mod;
    cout<<a[n]<<endl;
    return 0;
}