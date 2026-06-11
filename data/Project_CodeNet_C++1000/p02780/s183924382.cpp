#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double mean(ll p)
{
            if(p%2==0)return p/2.0+0.5; 
            else return (p-1.0)/2.0+1.0; 
} 

int main()
{
    ll N,K;
    cin >> N >> K;
    vector<double> m(N,0);
    vector<double> S(N+1,0);
    for(ll i=0;i<N;i++)
    {
        ll p;cin>>p;
        m[i]=mean(p);
    }
    S[0]=0;
    for(ll i=0;i<N;i++)
    {
        S[i+1]+=S[i]+m[i];
    }

    double res = 0;
    for(ll i=0;i<=N-K;i++){
        res=max(res,S[i+K]-S[i]);
    }
    cout << std::fixed << std::setprecision(6) << res << endl;
}