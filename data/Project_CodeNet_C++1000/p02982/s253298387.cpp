#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n,d;
    cin>>n>>d;
    vector<vector<int>> p(n, vector<int>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> p.at(i).at(j);
        }
    }

    ll ans=0;
    for (int i = 0; i < n; i++) {
        for(int j=i+1;j<n;j++){
            ll sum=0;
            for(int k=0;k<d;k++){
                sum+=(p.at(i).at(k) - p.at(j).at(k)) * (p.at(i).at(k) - p.at(j).at(k));
            }
            ll num = sqrt(sum);
            if(sum - (num*num)==0)ans++;
        }
    }
    cout<<ans<<endl;

}
