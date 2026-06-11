#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    //input
    int n,k,q; cin >> n >> k >> q;
    vector<int> a(q + 1,0);
    for(int i = 1; i < q + 1; i++) cin >> a[i];

    //compute
    vector<int> p(n + 1, k - q);
    for(int i = 1; i < q + 1; i++) {
        p[a[i]] = p[a[i]] + 1;
    }

    //output
    for(int i = 1;i < n + 1 ; i++) {
        if(p[i] > 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    } 
}