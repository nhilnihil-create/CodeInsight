#include <bits/stdc++.h>
#define ll long long
#define ALL(x) x.begin(),x.end()
#define MOD (1000000000+7)
using namespace std;
#define PI 3.14159265359
#define tMOD 998244353
#define mkpr(x,y) make_pair(x,y)



    int main(){
        ll N;
        cin>>N;

        vector<ll> x(N);
        vector<ll> y(N);
        for(ll i=0;i<N;i++)cin>>x[i]>>y[i];
        vector<ll> W(N),K(N);

        for(ll i=0;i<N;i++){
            W[i]=x[i]+y[i];
            K[i]=x[i]-y[i];
        }
        sort(ALL(W));
        sort(ALL(K));
        W.front();
        cout<<max(W.back()-W.front(),K.back()-K.front())<<endl;







    }