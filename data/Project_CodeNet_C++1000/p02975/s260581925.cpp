#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;
    vector<ll> A(n);
    map<ll,ll> mp;
    rep(i,n){
        cin>>A[i];
        mp[A[i]]++;
    }

    if(mp.size()==1){
        if(mp[0]!=0){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    if(mp.size()==2 && n%3==0){
        ll tmp=0;
        for(auto s : mp){
            if(s.first!=0) tmp=s.second;
        }

        if(mp[0]*3==n && tmp*3/2==n){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    if(mp.size()==3 && n%3==0){
        vector<ll> a(0);
        for(auto s : mp){
            a.push_back(s.first);
            if(s.second!=n/3){
                cout<<"No"<<endl;
                return 0;
            }
        }
        if((a[0]^a[1]^a[2])==0){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;
}