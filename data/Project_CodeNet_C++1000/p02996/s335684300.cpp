#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>ba(n);
    rep(i,n)cin>>ba[i].second>>ba[i].first;
    sort(rng(ba));
    ll t = 0;
    rep(i,n){
        if((ba[i].first-t)<ba[i].second){
            cout<<"No"<<endl;
            return 0;
        }
        t += ba[i].second;
    }
    cout<<"Yes"<<endl;

    return 0;
}