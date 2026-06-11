#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n;cin >>n;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    vector<ll>b;
    for (int i = n-1; i>=0;--i) {
        if(a[i]==1){
            b.push_back(i+1);
            a[0]=1-a[0];
            for (int j = 2; j*j<=(i+1); ++j) {
                if((i+1)%j==0){
                    a[j-1]=1-a[j-1];
                    if(j*j!=(i+1)) {
                        a[((i + 1) / j) - 1] = 1 - a[((i + 1) / j) - 1];
                    }
//                    cout <<j-1<<endl;
                }
            }
        }
    }
    ll m=b.size();
    cout <<m<<endl;
    for(auto e:b){
        cout <<e<<" ";
    }
    cout <<endl;
    return 0;
}