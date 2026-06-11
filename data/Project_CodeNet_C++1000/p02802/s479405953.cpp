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
    int n,m;
    cin >> n >> m;
    pair<int, string> sub[m];
    for(int i=0;i<m;i++) {
        cin >> sub[i].first >> sub[i].second;
        sub[i].first--;
    }

    pair<int, int> w[n];
    for(int i=0;i<n;i++){
        w[i].first=0;
        w[i].second=1;
    }

    int ac=0;
    int sum=0;
    for(int i=0;i<m;i++){
        if(w[sub[i].first].second){
            if(sub[i].second=="WA"){
                w[sub[i].first].first++;
            }else{
                ac++;
                sum+=w[sub[i].first].first;
                w[sub[i].first].second=0;
            }
        }  
    }

    cout << ac << ' ' << sum << endl;
}