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
    int k,x;
    cin >> k >> x;
    for(int i=x-k+1;i<x+k;i++) {
        if(i<-1000000 || i>1000000) continue; 
        cout << i << ' ';
    }
    cout << endl;
}