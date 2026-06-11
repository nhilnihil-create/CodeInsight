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
    int n; cin >> n;
    vector<int> a(n + 1,0);
    for(int i = 1; i < n + 1; i++) cin >> a[i]; 

    //compute
    vector<pair<int,int>> p(n + 1);
    for(int i = 1; i < n + 1; i++){
        p[i] = make_pair(a[i] , i);
    } 
    sort(p.begin() + 1 , p.end());

    //output
    for(int i = 1; i < n + 1;i++){
        cout << p[i].second << " ";
    }

}