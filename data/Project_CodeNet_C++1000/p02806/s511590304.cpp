#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
#define int long long
#define pii pair<int,int>
const int mod=1e9 + 7;
 
int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};
 

int dp[100][2];

int32_t main()
{
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);


 int n;

cin>>n;

map<string ,int>m;
vector<int>v(n+1);

for(int i=1;i<=n;i++)
{
  string s;
  cin>>s;
  int t;
  cin>>t;
  m[s]=i;
  v[i]=t;
  v[i]+=v[i-1];
}
string  x;
cin>>x;
int k=m[x];
cout<<v[n]-v[k];
 }

    
