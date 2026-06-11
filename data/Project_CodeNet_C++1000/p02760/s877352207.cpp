#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  int N,b;
  int A[3][3],linenum[8];
  vector<int> lines[8];

  REPI(3)
    REPJ(3)
      cin >> A[i][j];
  
  REPI(3)
  {
    lines[0].push_back (A[i][0]);
    lines[1].push_back (A[i][1]);
    lines[2].push_back (A[i][2]);
    lines[3].push_back (A[0][i]);
    lines[4].push_back (A[1][i]);
    lines[5].push_back (A[2][i]);
    lines[6].push_back (A[i][i]);
    lines[7].push_back (A[i][2-i]);
  }
  REPI(8)
    linenum[i] = 0;

  cin >> N;

  REPI(N)
  {
    cin >> b;
    REPJ(8)
    {
      if (find(lines[j].begin (),lines[j].end (), b) != lines[j].end ())
        linenum[j]++;
    }
  }

  REPI(8)
  {
    if (linenum[i]==3)
    {
        cout << "Yes" << endl;
        return 0;
    }    
  }
  cout << "No" << endl;

  return 0;
}

 