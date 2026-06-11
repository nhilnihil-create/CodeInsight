#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll Mod = 1e9 + 7;
ll n,k;
vector < ll > v[100100];

void Add_self(ll &x , ll y){
    x = (x + y)%Mod;
}

ll mul_self(ll x , ll y){
    return (x * y)%Mod;
}

ll Ans = 1;

ll DFS(ll x , ll p , ll depth){

    ll c = (depth == 0 ? k - 1 : k - 2);
    for(int i = 0;i<v[x].size() - (depth != 0);i++){
        Ans = mul_self(Ans , c);
        c--;
        c = max(c , (ll)0);
    }
    for(auto j : v[x])  if(j != p)  DFS(j , x , depth + 1);
}

int main()
{
    cin >> n >> k;
    Ans = k;
    for(ll i = 0;i<n - 1;i++){
        ll x,y;  cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1 , -1 , 0);
    cout << Ans;
    return 0;
}
