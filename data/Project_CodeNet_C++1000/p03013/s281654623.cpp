#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
#include<map>

using namespace std;

#define rep(i,N) for(int i=0;i<N;i++) //0から


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

#define MOD ((ll)1e+9 + 7)




//cout<<fixed<<setprecision(10);
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    rep(i,m){
        cin>>a[i];
        if(i!=0){
        }
    }


    vector<ll> cnt(n+1,0);
    cnt[0]=1;
    int c=0;
    rep(i,n+1){
        cnt[i]%=MOD;
        if(c<m && a[c]==i){
            c++;
            continue;
        }
        if(i+1<=n){
            cnt[i+1]+=cnt[i];
        }
        if(i+2<=n){
            cnt[i+2]+=cnt[i];
        }
    }

    cout<<cnt[n]<<endl;


    return 0;
}

