#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
typedef long long ll;
typedef int64_t in;
using namespace std;
#define INF 1000000007


int main() {
    while(1){
        int n;
        cin >> n;
        vector<string> f(n);
        if(n==0) break;
        
        for(int i=0; i<n; i++){
            cin >> f[i];
        }
        if(n==1) {
            cout << "0" << endl;
            continue;
        }
        int count=0;
        if(n % 2 == 0){
            for(int i=0; i<n; i+=2){
                if((f[i]=="lu" && f[i+1]=="ru")
                || (f[i] == "ru" && f[i+1] == "lu")
                || (f[i] == "ld" && f[i+1] == "rd")
                || (f[i] == "rd" && f[i+1] == "ld")){
                    count++;
                }
            }
        }else{
            for(int i=0; i<n-1; i++){
                if((f[i]=="lu" && f[i+1]=="ru")
                || (f[i] == "ru" && f[i+1] == "lu")
                || (f[i] == "ld" && f[i+1] == "rd")
                || (f[i] == "rd" && f[i+1] == "ld")){
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}
