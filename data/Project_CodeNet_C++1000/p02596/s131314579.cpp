// 173

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>

using namespace std;
using ll = long long int;
#define NUM 1000000007

int main(){
    int k;
    cin >> k;
    vector<ll> v;
    if(7%k == 0){
        cout << 1 << endl;
        return 0;
    }else if(k%2 == 0 || k%5 == 0){
        cout << -1 << endl;
        return 0;
    }else{
        v.push_back(7%k);
    }
    for(int i=1; i<k; i++){
        ll tmp = (v.at(i-1)*10 + 7)%k;
        if(tmp == 0){
            cout << i+1 << endl;
            return 0;
        }
        v.push_back(tmp);
    }
    return 0;
}

