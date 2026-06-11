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
    int N; cin >> N;
    vector<ll>x(N),y(N),z(N),w(N);
    for(int i = 0; i < N; i++) 
    {
        cin >> x[i] >> y[i];
        z[i] = x[i]+y[i];
        w[i] = x[i]-y[i];
    }
    sort(z.begin(),z.end());
    sort(w.begin(),w.end());
    ll ans = max(z[N-1]-z[0],w[N-1]-w[0]);
    cout << ans << endl;
}