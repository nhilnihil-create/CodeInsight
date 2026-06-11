#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n,m; std::cin >> n >> m;
    std::vector<int> v(n,0), sc(n+1,-1);
    bool flag = true;
    for(int i=0; i<m; i++){
        int s,c; std::cin >> s >> c;
        if(s==1 && c==0 && n!=1){
            flag = false;
        }else if(sc[s]>=0 && sc[s]!=c){
            flag = false;
        }else{
            sc[s] = c;
        }
    }

    if(flag==false){
        std::cout << "-1" << "\n";
        return 0;
    }

    for(int i=0; i<n; i++){
        if(sc[i+1]>=0){
            v[i] = sc[i+1];
        }
    }

    if(v[0]==0 && n>1) v[0] = 1;
    for(int i=0; i<n; i++){
        std::cout << v[i];
    }
    std::cout << "\n";
    return 0;
}