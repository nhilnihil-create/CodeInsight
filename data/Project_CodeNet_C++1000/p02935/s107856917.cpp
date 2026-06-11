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
    vector<double> v;
    for(int i=0;i<n;i++){
        int w;
        cin >> w;
        v.push_back(w);
    }
    sort(v.begin(),v.end());

    if(v.size()<2){
        cout << (v[0]+v[1])/2 << endl;
        return 0;
    }
    double tmp=(v[0]+v[1])/2;
    for(int i=2;i<n;i++){
        tmp=(tmp+v[i])/2;
        //cout << tmp << endl;
    }

    cout << tmp << endl;
}