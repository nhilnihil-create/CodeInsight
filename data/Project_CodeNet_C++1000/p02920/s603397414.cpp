#include <iostream>
#include <vector>
#include <limits>
#include <map>
#define MOD 1000000007
#include <algorithm>
#include <math.h>
#include <set>
#include <utility>

using namespace std;
    long long int dp[305][305][305];

int main(){
    int n,loopc;
    cin >> n;
    loopc = 1 << n;
    vector<int> a(loopc);
    multiset<int> rest;
    for(int i = 0; loopc > i; i++){
        cin >> a[i];
        rest.insert(a[i]);
    }

    vector<int> cur;
    cur.reserve(loopc);
    cur.push_back(*(--rest.end()));
    rest.erase(--rest.end());

    while(rest.size()){
        vector<int> ad;
        ad.reserve(cur.size() * 2);
        for(auto c : cur){
            auto itr = rest.lower_bound(c);
            if(itr == rest.begin()) {
                cout << "No" << endl;
                return 0;
            }
            
            itr--;
            ad.push_back(*itr);
            rest.erase(itr);
        }

        for(auto c : ad) cur.push_back(c);
    }

    cout << "Yes" << endl;

    return 0;
}