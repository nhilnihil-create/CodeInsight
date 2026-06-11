#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pl= pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    string s;cin >>s;
    string w[3]={"Sunny","Cloudy","Rainy"};
    int key=-1;
    for (int i = 0; i < 3; ++i) {
        if(s==w[i]){
            key=i;
        }
    }
    key++;
    key%=3;
    cout <<w[key]<<endl;
}
