#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    int m, d;
    cin >> m >> d;

    int ans = 0;
    for(int i=1; i<=d; ++i){
        if(i/10<2||i%10<2)continue;
        int seki = (i/10)*(i%10);
        if(seki<=m&&seki>=1)ans++;
    }
    cout << ans << endl;
}