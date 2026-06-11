#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll long long
#define li long int

#define pb push_back
#define m <i> map<int>
#define v <i> vector<int>

#define rep(i, n) for(int i=0; i<n; i++)

int main()
{
  IOS;
  int arr[3][3];
  for (int i=0; i<3; i++)
    {
      for (int j=0; j<3; j++)
	{
	  cin >> arr[i][j];
	}
    }
  int n;
  cin >> n;
  int x[n];
  for (int i=0; i<n; i++)
    {
      cin >> x[i];
    }
  bool q[3][3];
  for (int i=0; i<3; i++)
    {
      for (int j=0; j<3; j++)
	{
	  q[i][j]=false;
	  for (int k=0; k<n; k++)
	    {
	      if (x[k]==arr[i][j])
		q[i][j]=true;
	    }
	}
    }
  string ans="No";
  for (int i=0; i<3; i++)
    {
      if (q[i][0] && q[i][1] && q[i][2])
	ans="Yes";
    }
  for (int i=0; i<3; i++)
    {
      if (q[0][i] && q[1][i] && q[2][i])
	ans="Yes";
    }
  if (q[0][0] && q[1][1] && q[2][2])
    ans="Yes";
  if (q[0][2] && q[1][1] && q[2][0])
    ans="Yes";
  cout << ans << endl;
  return 0;
}
