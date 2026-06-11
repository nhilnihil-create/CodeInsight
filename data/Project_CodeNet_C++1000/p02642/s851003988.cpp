#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
const int possible_a=1e6+7;
int main(){
    cin >> n;
    vector<int> v; v.resize(n);
    vector<int> dp(possible_a, 0);
    for(int i=0; i<n; i++) cin >> v[i];
    int max_a = *max_element(v.begin(), v.end());
    for(auto i : v){
        for(int j=i; j<=max_a; j+=i){
            if(j==i) dp[j] += 1;
            else dp[j] += 2;
        }
    }
    int count = 0;
    for(auto i : v) if(dp[i]==1) count++;
    cout << count << "\n";
    return 0;
}