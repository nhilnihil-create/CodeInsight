#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
  IOS;
  int n;
  cin >> n;
  int freq[n];
  map<string, int> arr;
  for (int i=0; i<n; i++)
    {
      string s;
      cin >> s;
      arr[s]+=1;
    }
  int mx=0;
  for (const auto& x: arr)
    {
      int q=x.second;
      if (q>mx)
	mx=q;
    }
  for (auto it=arr.begin(); it!=arr.end(); it++)
    {
      if (it->second==mx)
	cout << it->first << endl;
    }
  return 0;
}
