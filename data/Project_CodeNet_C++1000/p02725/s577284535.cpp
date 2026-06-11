#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    fast_cin;
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif


    ll K,N;
    cin>>K>>N;

    vector<ll> A(2*N);

    vector<ll> B;

    for(ll i=0;i<N;i++){
        cin>>A[i];
        //if(A[i]==0)
            //A[i]=K;
       // A.push_back(A[i]);
       A[i+N]=A[i];
       //if(A[i+N]==0)
     //   A[i+N]=K;
    }

 
    ll M=2*N;
    for(ll i=0;i<M-1;i++){
        if(A[i]<=A[i+1])
        B.push_back(abs(A[i]-A[i+1]));
        else B.push_back(K-abs(A[i]-A[i+1]));
    }

    // for(ll i=0;i<A.size();i++){
    //     cout<<A[i]<<" ";
    // }
    // cout<<"\n";
    //   for(ll i=0;i<B.size();i++){
    //     cout<<B[i]<<" ";
    // }
    // cout<<"\n";

    ll m=B.size();
    ll q=m/2;

    ll add=0;
    for(ll i=0;i<q;i++){
        add+=B[i];
    }
    ll ans=add;
    for(ll i=q;i<m;i++){
        add=abs(add+B[i]-B[i-q]);
        ans=min(ans,add);
    }
    cout<<ans<<"\n";


}
