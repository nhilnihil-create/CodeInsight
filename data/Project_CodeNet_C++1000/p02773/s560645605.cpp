#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string, int> table;
    rep(i,n){
        string s;
        cin >> s;
        table[s]++;
    }
    int maxValue = 0;
    for(const auto& p : table) maxValue = max(maxValue, p.second);
    for(const auto& p : table){
        if(maxValue != p.second) continue;
        cout << p.first << endl; 
    }
}