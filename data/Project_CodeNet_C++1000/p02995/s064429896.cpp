#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll e=b/c-(a-1)/c;
    ll f=b/d-(a-1)/d;
    ll temp=c/__gcd(c,d)*d;
    ll g=b/temp-(a-1)/temp;
    cout<<(b-a+1)-(e+f-g)<<endl;
}