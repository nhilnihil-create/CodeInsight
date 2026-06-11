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

vector<bool> func(int x, int len){
    vector<bool> v(len, false);
    int i=0;
    for(int i=0; x!=0; i++){
        if(x%2 == 0) v.at(i) = false;
        else if(x%2 == 1) v.at(i) = true;
        x /= 2;
    }
    reverse(v.begin(), v.end());
    return v;
}

int main(){
    int h, w, k, ans=0;
    cin >> h >> w >> k;
    string c;
    vector<vector<bool>> v(h, vector<bool>(w));
    for(int i=0; i<h; i++){
        cin >> c;
        for(int j=0; j<w; j++){
            if(c.at(j) == '#') v.at(i).at(j) = true;
            else if(c.at(j) == '.') v.at(i).at(j) = false;
        }
    }
    int h_2 = pow(2, h), w_2 = pow(2, w);
    for(int i=0; i<h_2; i++){
        for(int j=0; j<w_2; j++){
            int count = 0;
            auto h_bit = func(i, h), w_bit = func(j, w);
            for(int x=0; x<h; x++){
                for(int y=0; y<w; y++){
                    if(!h_bit.at(x) && !w_bit.at(y) && v.at(x).at(y)) count++;
                }
            }
            if(count == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
