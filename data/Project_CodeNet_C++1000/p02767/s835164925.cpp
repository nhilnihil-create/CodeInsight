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
using intl = int64_t;
using graph = vector<vector<int> >;
int main(){
    int n;
    cin >> n;
    int x[n];
    for(int i=0;i<n;i++) cin >> x[i];

    int sum = 1000000;
    for(int i=1;i<=100;i++){
        int subsum=0;
        for(int j=0;j<n;j++){
            subsum += (i-x[j])*(i-x[j]);
        }

        sum = min(sum,subsum);
    }

    cout << sum << endl;
}