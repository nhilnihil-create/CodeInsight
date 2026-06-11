#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
    int h, w, k; cin >> h >> w >> k;
    vector<bool> grid(h*w);

    char cij;
    int sum = 0;
    rep(i, h){
        rep(j, w){
            cin >> cij;
            if(cij == '#'){
                grid.at(i*w+j) = true;
                sum++;
            }else{
                grid.at(i*w+j) = false;
            }
        }
    }
    
    int ans = 0, cnt = 0;
    rep(red, 1<<(h+w)){
        rep(i, h){
            rep(j, w){
                int index = i*w+j;
                if(!(red & ((1<<j) + (1<<(i+w))))){
                    if(grid.at(i*w+j)) cnt++;
                }
            }
        }
        if(cnt == k) ans++;

        cnt = 0;
    }

    cout << ans << endl;
    return 0;
}