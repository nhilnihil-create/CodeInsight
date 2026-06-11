#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
 
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

int main() {
    int a[9];
    for(int i = 0; i < 9; i++){
        cin >> a[i];
    }
    int n;
    cin >> n;
    int aa[n];
    for(int j = 0; j < n; j++){
     cin >> aa[j];
     if(aa[j] == a[0]){
         a[0] = 0;
     }
     if(aa[j] == a[1]){
         a[1] = 0;
     }
     if(aa[j] == a[2]){
         a[2] = 0;
     }
     if(aa[j] == a[3]){
         a[3] = 0;
     }
     if(aa[j] == a[4]){
         a[4] = 0;
     }
     if(aa[j] == a[5]){
         a[5] = 0;
     }
     if(aa[j] == a[6]){
         a[6] = 0;
     }
     if(aa[j] == a[7]){
         a[7] = 0;
     }
     if(aa[j] == a[8]){
         a[8] = 0;
     }
    }
    if(a[0] == 0 && a[1] == 0 && a[2] == 0){
        cout << "Yes";
        return 0;
    }else if(a[3] == 0 && a[4] == 0 && a[5] == 0){
        cout << "Yes";
        return 0;
    } else if(a[6] == 0 && a[7] == 0 && a[8] == 0){
        cout << "Yes";
        return 0;
    } else if(a[0] == 0 && a[3] == 0 && a[6] == 0){
        cout << "Yes";
        return 0;
    }else if(a[1] == 0 && a[4] == 0 && a[7] == 0){
        cout << "Yes";
        return 0;
    }else if(a[2] == 0 && a[5] == 0 && a[8] == 0){
        cout << "Yes";
        return 0;
    } else if(a[2] == 0 && a[4] == 0 && a[6] == 0){
        cout << "Yes";
        return 0;
    }else if(a[0] == 0 && a[4] == 0 && a[8] == 0){
        cout << "Yes";
        return 0;
    } else{
        cout << "No";
    }
    return 0;
}