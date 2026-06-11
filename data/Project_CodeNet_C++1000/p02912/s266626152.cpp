#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007 

int main()
{
  fast
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output2.txt", "w", stdout);
  #endif

  ll n,m;
  cin>>n>>m;
  ll i,j;
  vector<ll> a(n);
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  make_heap(a.begin(), a.end()); 
  
  while(m!=0)
  {
    ll temp=a.front();
    temp/=2;

    pop_heap(a.begin(), a.end()); 
    a.pop_back(); 
    
    a.push_back(temp); 

    m--;
  }
  ll sum=0;
  for(auto it=a.begin();it!=a.end();it++)
  {
    sum+=(*it);
  }
  cout<<sum<<endl;

  return 0;
}