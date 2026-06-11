#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int N=200000;

void Run()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
//ll s[N],c[N];
ll h=1000000000000000000;
ll a[N];
vector<string>v;
map<string,int>mp;
int main()
{
    Run();
    ll A;
  cin>>A;
  string B;
  cin>>B;
  ll b = (B[0]-'0')*100+(B[2]-'0')*10+(B[3]-'0');
  cout<<A*b/100<<endl;
}
