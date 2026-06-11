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
    rep(i,n){
        cin>>a[i];
        if(a[i]%2==0){
            if(a[i]%5!=0&&a[i]%3!=0){
                cout<<"DENIED"<<endl;
                return 0;
            }
        }
    }
    cout<<"APPROVED"<<endl;
  
}
