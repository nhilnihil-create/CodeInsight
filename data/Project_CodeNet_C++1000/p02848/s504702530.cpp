#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define L INT_MIN
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;

int main() 
{
  fastio;
  
  int n;
  cin>>n;
  string s;
  cin>>s;
  int x=int('Z');
 // cout<<x;
  for(int i=0;i<s.length();i++)
  {
    s[i]=s[i]+n;
    if(s[i]>'Z')
      s[i]=s[i]-26;

  }
  cout<<s;
 
}