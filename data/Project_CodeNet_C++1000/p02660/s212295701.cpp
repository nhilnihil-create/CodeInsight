#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
#include<map>

using namespace std;

#define rep(i,N) for(ll i=0;i<N;i++) //0から


typedef long long ll;




ll binary_search(vector<ll> a, ll n, ll key){
    ll right = n, left = -1;
    ll md = (right + left) / 2;

    while(right - left > 1){
        if(a[md] <= key){
            right = md;
        }else{
            left = md;
        }
        md = (right + left) / 2;
    }
    if(left == -1) return -1; //無い場合
    return right;
}

vector<ll> prime;
void Prime(ll n){ //線形篩,素数列挙
    vector<ll> p(n,0);
    p[0]=1;
    p[1]=1;
    for(ll i=2;i<n;i++){
        if(p[i]==0){
            prime.push_back(i);
            p[i]=i;
        }
        ll k=prime.size();
        for(ll j=0;j<k && i*prime[j]<n && prime[j]<=p[i];j++){
            p[i*prime[j]]=prime[j];
        }
    }
}

ll gcd(ll a,ll b){
    if(a<b){
        swap(a,b);
    }
    //a>=b
    ll r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

#define MOD ((ll)1e+9 + 7)



//cout<<fixed<<setprecision(10);
int main(){
    ll n;
    cin>>n;

    vector<ll> cnt;
    ll m=n;
    for(ll i=2;i*i<=m && n>1;i++){
        if(n%i==0){
            ll tmp=0;
            while(n%i==0){
                tmp++;
                n/=i;
            }
            cnt.push_back(tmp);
        }
    }
    ll ans=0;
    if(n>1) ans++;
    n=cnt.size();
    
    rep(i,n){
        ll k=0;
        while(((k+1)*(k+2))/2 <= cnt[i]){
            k++;
        }
        ans+=k;
    }

    cout<<ans<<endl;
    

    return 0;
}

