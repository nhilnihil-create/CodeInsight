#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

static const int MAX = 200000;

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
std::vector<int> Eratosthenes( const int N )
{
    std::vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    std::vector<int> P;
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}
int main()
{
    int N;
    cin >> N;
    for( const auto &x: Eratosthenes( 1000000 ))
    {
      if (N <= x) {
        cout << x << endl;
        break;
      }
    }
    return 0;
}
