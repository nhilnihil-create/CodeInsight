#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    string s;
    cin >> s;
    vector<int> ans(int(s.size()),0);
    int r_count = 0;
    for(int i = 0; i < s.size()-1;i++){
        if(s.at(i) == 'R') r_count++;
        if(s.at(i) == 'R' && s.at(i+1) == 'L'){
            ans.at(i) += (r_count+1)/2;
            ans.at(i+1) += (r_count)/2;
            r_count = 0;
        }
    }
    int l_count = 0;
    for(int i = s.size()-1;i >= 1;i--){
        if(s.at(i) == 'L') l_count++;
        if(s.at(i) == 'L' && s.at(i-1) == 'R'){
            ans.at(i) += (l_count+1)/2;
            ans.at(i-1) += (l_count)/2;
            l_count =0;
        }
    }
    for(int i = 0;i <s.size();i++) cout << ans.at(i) << " ";
    cout << endl;
}