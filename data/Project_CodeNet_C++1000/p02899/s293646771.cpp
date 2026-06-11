#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    
    int n;
    cin >> n;
    
    map<int,int> mp;
    
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        
        mp[a] = i + 1;
    }
    
    for (auto p : mp){
        cout << p.second << " ";
    }
    cout << endl;
    
}
