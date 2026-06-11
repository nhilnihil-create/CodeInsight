#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <numeric>
using namespace std;

int main() {
    double n,d;
    cin >> n >> d;
    
    vector<vector<int>> data(n, vector<int>(d));
    rep(i,n) {
     rep(j,d) {
      cin >> data.at(i).at(j);
     }
    }
    
        int count = 0;
    
    rep(i, n - 1) {
     for(double j = i; j < n - 1;j++) {
             
        double dist = 0;
        rep(k, d) {
         dist += ((data.at(i).at(k) - data.at(j + 1).at(k)) * (data.at(i).at(k) - data.at(j + 1).at(k)));
        } 
             if(sqrt(dist) == int(sqrt(dist))){
              count++;
             }
     
      }
    }
 cout << count;
}