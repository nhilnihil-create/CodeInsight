#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 10000000000000
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
    ll N;
    cin >> N;
    vector<pair<ll,ll>> v;
    for(ll i=1;i<=sqrt(N);i++){
        if(N%i==0){
            v.push_back(make_pair(i, N/i));
        }
    }
    
    ll min=INF;
    for(auto x:v){
        if(x.first-1+x.second-1<min){
            min = x.first-1+x.second-1;
        }
    }
    cout << min << endl;
    return 0;
}