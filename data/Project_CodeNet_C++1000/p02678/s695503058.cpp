#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,s,e) for(ll i=s;i<e;++i)

int main()
{
    ll N,M;
    cin >> N >> M;

    ll A[M],B[M];
    F(i,0,M) cin >> A[i] >> B[i];

    vector<ll> G[N];
    F(i,0,M){
        G[A[i]-1].push_back(B[i]-1);
        G[B[i]-1].push_back(A[i]-1);
    }

    ll S[N]={0};
    bool seen[N];
    F(i,0,N) seen[i]=false;
    queue<ll> q;
    q.push(0);
    seen[0]=true;

    while(!q.empty()){
        ll t=q.front(); q.pop();
        for(auto nv : G[t]){
            if(!seen[nv]){
                seen[nv]=true;
                S[nv]=t;
                q.push(nv);
            }
        }
    }

    bool f=true;
    F(i,0,N){
        if(!seen[i]) f=false;
    }

    if(f){
        cout << "Yes" << endl;
        F(i,1,N){
            cout << S[i]+1 << endl;
        }
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}