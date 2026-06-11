#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main()
{
ll N; cin >> N;
ll mod = 1e9+7;

ll ans10 = 1;
ll ans9 = 1;
ll ans8 = 1;
for(int i = 0 ; i < N ; i++)
{
    ans10 = (ans10*10) % mod ;
    ans9 = (ans9*9) % mod ;
    ans8 = (ans8*8) % mod ;
}

cout << (ans10 - 2*ans9 + ans8 + 2*mod) % mod;
}