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
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b&&a==c){
        cout<<no<<endl;
        return 0;
    }
    if(a==b) cout<<yes<<endl;
    else if(a==c) cout<<yes<<endl;
    else if(c==b) cout<<yes<<endl;
    else cout<<no<<endl;
  
}
