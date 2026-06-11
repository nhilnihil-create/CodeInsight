#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  int N,cnt,cur,p,res;
  char pin[3];
  string S;

  cin >> N;
  cin >> S;

  REPI(3)
    pin[i] = '0';

  cnt = 0;
  res = 0;
  while (cnt < 1000){
    cur = 0;
    p = 0;

    while (p<S.size ())
    {
      if (S[p] == pin[cur])
      {
        if (cur == 2)
        {
          res++;
          break;
        }
        cur++;
      }

      p++;
    }
    
    cur = 0;
    pin[cur]++;
    while (pin[cur] > '9' && cur < 2)
    {
      pin[cur] = '0';
      cur++;
      pin[cur]++;      
    }
    cnt++;
  }
  
  cout << res << endl;
  
  return 0;
}