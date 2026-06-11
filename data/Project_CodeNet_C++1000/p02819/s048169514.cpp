#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



vector<int> Eratosthenes( const int N )
{
    vector<bool> is_prime( N + 1 );
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
//100003
int main()
{
    int N;
    cin >> N;
    for( const auto &x: Eratosthenes( 100004 ) )
    {
        if(x>=N){
            cout << x<<endl;
            break;
        }
    }
    return 0;
}