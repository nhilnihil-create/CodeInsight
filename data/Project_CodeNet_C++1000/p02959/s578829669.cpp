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

long long larger(long long a, long long b){
  if(a >= b){
    return a;
  }else{
    return b;
  }
}

long long smaller(long long a, long long b){
  if(a <= b){
    return a;
  }else{
    return b;
  }
}

int main() {
    //input
    int n; cin >> n;
    long long counter = 0;
    vector<long long> a(n + 2, 0);
    vector<long long> b(n + 2, 0);
    for(int i = 1; i < n + 2; i++) cin >> a[i];
    for(int i = 1; i < n + 1; i++) cin >> b[i];

    //compute
    for(int i = 1; i < n + 2; i++){
        counter += smaller(a[i] + a[i + 1],b[i]);
        a[i + 1] = larger(0 , a[i + 1] - larger(0, b[i] - a[i]));
    } 

    //output
    cout << counter << endl;
}
