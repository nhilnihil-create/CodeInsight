// 173

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>

using namespace std;
using ll = long long int;
#define NUM 1000000007

int main(){
    int n, ans=0;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                if(v.at(i) == v.at(j) || v.at(i) == v.at(k) || v.at(j) == v.at(k) || v.at(i)+v.at(j) <= v.at(k)) continue;
                else ans++;
            }
        }
    }
    cout << ans << endl;
}