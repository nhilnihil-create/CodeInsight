#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#define ll long long
#define add push_back
 
using namespace std; 


int main() {

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;  t = 1; //cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int answ = 0;
        for(int i = 0; i < k; i++)
            answ += v[i];
        cout << answ << endl;
    }
    return 0;
}