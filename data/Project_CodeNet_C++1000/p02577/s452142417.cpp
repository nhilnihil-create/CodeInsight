#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define endl "\n"
#define _  <<" "<<
#define eb(x) emplace_back(x)
#define maxelem(v) *max_element(v.begin(),v.end())
#define minelem(v) *min_element(v.begin(),v.end())
#define FOR(a,b) for(int i=int(a);i<int(b);++i)

using namespace std;

const int mod = 1e9+7;

void izlaz(string br)
{
  if(!br.size())
    exit(EXIT_SUCCESS);
  cout<<br;
  exit(EXIT_SUCCESS);

}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string n;
  unsigned long long sumd=0;
  cin>>n;
  if(n=="0")
    cout<<"Yes";
  else
  {
      for(int i=0;i<n.size();i++)
        sumd+= n[i]-'0';

    if(sumd%9==0)
        cout<<"Yes";
    else
        cout<<"No";
  }
 return 0;
}
