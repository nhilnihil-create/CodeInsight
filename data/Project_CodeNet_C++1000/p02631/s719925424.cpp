#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

string yes="Yes",no="No";



int main() {
    int n;
    cin>>n;
    vin a(n);
    int s=0;
    rep(i,n){
        cin>>a[i];
        s=(s^a[i]);
    }
    bitset<32> t(s);
    rep(i,n){
        bitset<32> u(a[i]);
        rep(j,32){
            if(t[j]) u.flip(j);
        }
        cout<<u.to_ullong()<<" ";
    }
    cout<<endl;
    
  

}
