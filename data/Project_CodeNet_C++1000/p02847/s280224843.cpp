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
  
  
  map<string,int> mp;
  mp["SUN"]=7;
  mp["MON"]=6;
  mp["TUE"]=5;
  mp["WED"]=4;
  mp["THU"]=3;
  mp["FRI"]=2;
  mp["SAT"]=1;
  string s;
  cin>>s;
  cout<<mp[s]; 
 
}