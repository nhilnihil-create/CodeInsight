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
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
    int N;
    cin >> N;
    map<string, int> mp;
    //ll ans=0;
    rep(i,N){
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        //ans += mp[s];
        mp[s] +=1;
    }

    ll ans=0;
    for(auto p :mp){
        ans += (ll) p.second*(p.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}

