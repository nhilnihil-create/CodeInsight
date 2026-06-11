#include <bits/stdc++.h>
#define INF 1e7
#define mod 1000000007

using namespace std;
typedef long long int ll;
typedef tuple<int,int,int> tii;
typedef tuple<long long int,long long int,long long int> tll;
typedef tuple<double,double,double> tdd;


int main()
{
    ll N; cin >> N;
    vector<ll>A(N+1); 
    for(int i = 0; i <= N; i++) A[i] = 0;
    A[0] = 3;
    ll ans = 1;
    for(int i = 0; i < N; i++)
    {
        ll a; cin >> a;
        ans *= A[a];
        ans %= mod;
        A[a]--;
        A[a+1]++;
    }
    cout << ans << endl;
}