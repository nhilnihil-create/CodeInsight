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
    vector<int> d;
    for(int i=0;i<n;i++){
        int e;
        cin >> e;
        d.push_back(e);
    } 

    sort(d.begin(),d.end());

    cout << d.at(d.size()/2)-d.at(d.size()/2-1) << endl;
}