#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<string>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;

int main(){
    map<string,int> mp;
    int N;  cin >> N;
    ll tmp, ans;
    for(int i=0; i<N; i++){
        string s;   cin >> s;
        sort(all(s));
        mp[s]++;
    }
    ans = 0;
    for(auto i=mp.begin(); i != mp.end(); i++){
        tmp = i->second;
        ans += tmp*(tmp-1)/2;
    }
    cout << ans << endl;
    return 0;
}