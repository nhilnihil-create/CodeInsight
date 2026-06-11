#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
int main() {
  // input
    int n,m;cin >> n >> m;
    //string str = "000000";
    vector<int> str(n + 1);
    vector<int> s(m + 1);
    vector<int> c(m + 1);
 
    for(int i = 1; i < n + 1; i++) str[i] = 0;
  	if(n > 1){
        str[1] = 1;
    }
  
    if(m > 0){
        for(int i = 1; i < m + 1; i++) cin >> s[i] >> c[i];
    }else{
        for(int i = 1; i < n + 1; i++) cout << str[i]; 
        cout << endl;
        return 0;
    }
 
  // compute
    set<int> st1,st2,st3;
    
    for(int i = 1; i < m + 1; i++){
        if(s[i] > n){
        }else{
            switch(s[i]){
                case 1:
                    st1.insert(c[i]);
                    break;
                case 2:
                    st2.insert(c[i]);
                    break;                
                case 3:
                    st3.insert(c[i]);
                    break;
            }
        }
        } 
    if(st1.size() > 1 || st2.size() > 1 || st3.size() > 1){
        cout << -1 << endl;
        return 0;
    }else{
      for(int i = 1; i < m + 1; i++) str[s[i]] = c[i];
    }        
 
  // output  
    if(str[1] == 0 && n != 1){
            cout << -1 << endl;
        }else{
             for(int i = 1; i < n + 1; i++) cout << str[i]; 
      		 cout << endl;
        }
}