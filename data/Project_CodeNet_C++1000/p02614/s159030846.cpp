#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W,K;
    cin >> H >> W >> K;
    vector<vector<char>> c(H,vector<char>(W));
    vector<vector<int>> d(H,vector<int>(W));
    vector<vector<int>> e(H,vector<int>(W));
    bool HFlag = false;
    bool WFlag = false;
    int a = 0;
    int cnt =0;
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            cin >> c.at(i).at(j); 
        }
    }
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            if(c.at(i).at(j)=='.') {
                d.at(i).at(j) = 0;
            }else{
                d.at(i).at(j) = 1;
            }
        }
    }

    for(int i=0;i<pow(2,H)*pow(2,W);i++) {
        e = d;
        a = 0;
        bitset<12> value(i);

        for(int j=0;j<H;j++) {
            if (value[(H+W-1)-j] == 1) { //このときその行をすべて塗りつぶす
                HFlag = true;
            }
            for(int k=0;k<W;k++) {
                if (HFlag == true) {
                    e.at(j).at(k) = 0;
                }
            }
            HFlag = false;
        }
        for(int j=0;j<W;j++) {
            if(value[(W-1)-j] == 1) {
                WFlag = true;
            }
            for(int k=0;k<H;k++) {
                if (WFlag == true) {
                    e.at(k).at(j) = 0;
                }
            }
            WFlag = false;            
        }

        for(int j=0;j<e.size();j++) {
            a += accumulate(e.at(j).begin(),e.at(j).end(),0);
        }
        if (a == K) {
            cnt++;
        }
    }
    cout << cnt << endl;
    
    return 0;
}