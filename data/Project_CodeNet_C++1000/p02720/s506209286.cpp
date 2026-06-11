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
#define vnn(x,y,name) vector<vector<int>> name(x, vector<int>(y));

string yes="Yes",no="No";

int main() {
    ll k;
    cin>>k;
    ll cnt=0;
    queue<ll> s;
    rell(i,9){
        s.push(i+1);
        cnt++;
        if(cnt==k){
            cout<<k<<endl;
            return 0;
        }
    }
    while(!s.empty()){
        ll j=s.front();
        if(j%10!=0){
            s.push(10*j+j%10-1);
            cnt++;
            if(cnt==k){
                cout<<10*j+j%10-1<<endl;
                return 0;
            }
        }
        s.push(10*j+j%10);
        cnt++;
        if(cnt==k){
            cout<<10*j+j%10<<endl;
            return 0;
        }
        if(j%10!=9){
            s.push(10*j+j%10+1);
            cnt++;
            if(cnt==k){
                cout<<10*j+j%10+1<<endl;
                return 0;
            }
        }
        s.pop();
    }
    
    
}
