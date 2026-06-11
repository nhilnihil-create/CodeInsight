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
    ll n;
    cin>>n;

    if(n==1){
        cout<<"0"<<endl;
        return 0;
    }

    int flag=0;
    for(ll i=2; i<=sqrt(n); i++){
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"1"<<endl;
        return 0;
    }

    vector<ll> prime=prime_list(sqrt(n));
    vector<ll> v;

    ll num=n;
    rep(i, prime.size()){
        if(num%prime[i]==0){
            ll prime_num=0;
            while(num%prime[i]==0){
                prime_num++;
                num=num/prime[i];
                if(num==0) break;
            }
            v.push_back(prime_num);
        }
    }
    if(num>1) v.push_back(1);

    ll ans=0;
    rep(i, v.size()){
        ll num=v[i];
        ll number=1;
        ll a=2;
        while(num>=number){
            ans++;
            number+=a;
            a++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}