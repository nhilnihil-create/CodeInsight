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
    vector<pair<int,int> > a;
    for(int i=0;i<n;i++){
        int b;
        cin >> b; 
        a.push_back(make_pair(b,i+1));
    }

    sort(a.begin(),a.end());

    for(int i=0;i<n;i++) cout << a.at(i).second << ' ';
    cout << endl; 
}