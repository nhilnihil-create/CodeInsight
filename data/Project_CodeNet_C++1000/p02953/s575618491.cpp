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
    int h[n];
    for(int i=0;i<n;i++) cin >> h[i];

    int m=h[0];
    for(int i=1;i<n;i++) {
        m = max(h[i],m);
        if(m-h[i]>1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}