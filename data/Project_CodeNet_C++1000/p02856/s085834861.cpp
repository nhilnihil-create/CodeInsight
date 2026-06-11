#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m;
    cin>>m;
    ll d[m],c[m];
    ll dig=0,sum=0;
    for(int i=0;i<m;i++){
        cin>>d[i]>>c[i];
        dig+=c[i];
        sum+=d[i]*c[i];
    }
    cout<<(dig-1)+(sum-1)/9<<endl;
}