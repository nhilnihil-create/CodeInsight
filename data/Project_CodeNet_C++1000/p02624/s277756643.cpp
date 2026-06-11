#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

//return vector include prome number under N
vector<long long> prime_list(long long N){
    vector<long long> prime_list(N+1);
    for(long long i=0; i<N+1; i++){
        prime_list[i]=0;
    }

    prime_list[0]=1;
    prime_list[1]=1;

    for(long long i=2; i<=sqrt(N); i++){
        for(long long j=i*2; j<=N; j+=i){
            prime_list[j]=1;
        }
    }

    vector<long long> list;
    for(long long i=0; i<N+1; i++){
        if(prime_list[i]==0) list.push_back(i);
    }

    return list;
}

int main(){
    ll N;
    cin>>N;
    vector<ll> n(N+1, 0);

    vector<ll> prime=prime_list(N);
    vector<vector<ll>> div(N+1);

    ll ans=0;
    rep(i, N+1){
        if(i==0) continue;
        ll num=(N/i);
        ans+=(num*(num+1)*i)/2;
    }

    cout<<ans<<endl;

    // rep(i, prime.size()){
    //     //cout<<prime[i]<<endl;
    //     for(ll j=prime[i]; j<=N; j+=prime[i]){
    //         n[j]++;
    //         div[j].push_back(prime[i]);
    //     }
    // }

    // ll ans=0;
    // rep(i, N+1){
    //     if(i==0) continue;
    //     if(i==1){ ans++; continue; }
    //     ll num=1;
    //     int k=int(div[i].size());
    //     rep(j, k){
    //         //cout<<i<<" "<<i/div[i][j]+1<<endl;
    //         //num*=i*(i/div[i][j]+1);
    //         ll a, b, c;
    //         a=i;
    //         b=div[i][j];
    //         c=0;
    //         while(a>1){
    //             if(a%b!=0) break;
    //             a=a/b;
    //             c++;
    //         }
    //         num*=c+1;
    //         //cout<<num<<endl;
    //     }
    //     //cout<<i<<" "<<num<<endl;
    //     num=(num)*i;
    //     if(k>0) ans+=num;
    // }

    // cout<<ans<<endl;

    return 0;
}