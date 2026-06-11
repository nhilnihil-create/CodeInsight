#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll> a;
    for(int i=0;i<n;i++){
        ll f;
        cin >> f;
        a.push_back(f);
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    ll sum=0;
    int cnt=1;
    while(cnt<n){
        sum+=a.at(cnt/2);
        cnt++;
    }
    cout << sum << endl;
}