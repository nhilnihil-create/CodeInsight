#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n, m, k, fin1, fin2;
  bool aux=true;
  cin>>n>>m>>k;
  ll sumone[n+1], sumtwo[m+1];
  sumone[0]=0;
  sumtwo[0]=0;

  for( int i = 1 ; i <= n ; ++i )
  {
    cin>>sumone[ i ];
    sumone[ i ] = sumone[ i - 1 ] + sumone[ i ];
  }

  for(int i=1; i<=m; ++i)
  {
    cin>>sumtwo[ i ];
    sumtwo[ i ]= sumtwo[ i - 1 ] + sumtwo[ i ];
  }
  ll resp=0,  antecesor=m;
  for(int i=0; i<=n; ++i)
  {
    aux=true;
    if( k -sumone[ i ] >= 0)
    {
      ll cont = i, mem = k;
      mem -= sumone[ i ];
        while(aux)
        {
          if(mem - sumtwo[ antecesor ] < 0 )
          {
            antecesor--;
          }
          else
          {
            aux=false;
            cont+=antecesor;
          }
        }

        if(cont>resp)
        {
          resp=cont;
        }
    }
    else
    {
      break;
    }
  }
  cout<<resp<<ENDL;
  return 0;
}
