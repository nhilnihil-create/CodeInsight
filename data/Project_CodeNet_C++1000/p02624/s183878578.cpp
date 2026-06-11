#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int xx;
//bool is_prime(ll x){
//if(x<=1) return 0;
//for(int i=2;i*i<=x;i++){
//    if(x%i==0)return 0;
//}
//return 1;
//}
ll mod=1e7;
int main(){
ll x;
cin>>x;
vector<ll> v1(x+1,0);
for(ll i=1;i<=x;i++){
 for(ll j=0;j<=x;j+=i)
        v1[j]++;
}
ll total=0;
for(ll i=1;i<=x;i++){
total+=(i*(ll)v1[i]);
}
cout<<total;
}

