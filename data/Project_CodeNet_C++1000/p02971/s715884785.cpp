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
    vector<int> a(n + 1, 0);
    vector<int> c(n + 1, 0);
    for(int i = 1; i < n + 1; i++) cin >> a[i];
    for(int i = 1; i < n + 1; i++) c[i] = a[i];
  

    //compute
    int hit = 0;
    sort(c.begin() + 1 , c.end());
    reverse(c.begin() + 1 , c.end());
    hit = count(c.begin() + 1 , c.end(),c[1]);

    //output
    if(hit >= 2){
        for(int i = 1; i < n + 1; i++){
            cout << c[1] << endl;
        }
        }else{
            for(int i = 1; i < n + 1; i++){
            if(a[i] == c[1]){
                cout << c[2] << endl;
        }else{
	        	cout << c[1] << endl;
        }
        }
        }

}
