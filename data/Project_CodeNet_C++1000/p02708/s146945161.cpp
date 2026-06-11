#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define DEBUG 0 
#define LIMIT (LONG_MAX / 10)
#define POSITIVE_LAST_D (LONG_MAX % 10)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;

int main(){
    ll n,k;
    cin>>n>>k;

    ll mod1097=pow(10,9)+7;
    ll temp=0;
    for(ll s=k;s<=n+1;s++){
        ll mink=(s*(s-1))/2,maxk=((2*n-s+1)*s)/2;
        temp+=(maxk-mink+1);
        temp%=mod1097;
    }

    cout<<temp<<endl;
    return 0;
}