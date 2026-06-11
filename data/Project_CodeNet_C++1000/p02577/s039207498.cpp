#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll N=1e6+1;

ll gcd(ll a,ll b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

ll fact[N];
bool prime[N];

void sieve(){
    for(ll i=2;i<N;i++){
        if(prime[i]==true){
            for(ll j=i*i;j<=N;j+=i){
                prime[j]=false;
                fact[j]=i;
            }
        }
    }
}

int main(){
    string n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n.size();i++)
        sum+=n[i]-'0';
    if(sum%9==0) cout<<"Yes \n";
    else cout<<"No \n";
    return 0;
}
