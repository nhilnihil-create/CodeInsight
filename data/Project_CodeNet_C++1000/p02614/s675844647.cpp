#include <bits/stdc++.h>
using namespace std;
int main(void){
    int h,w,k;
    cin>>h>>w>>k;
    char c;
    std::vector<vector<char>> vec(h,vector<char>(w));
    std::vector<vector<char>> copy(h,vector<char>(w));
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            cin>>c;
            vec[i][j]=c;
            copy[i][j]=c;
        }
    }
    int ans=0;
    for (int bith=0;bith<(1<<h);bith++) {
        std::deque<int> H;
        for (int i=0;i<h;i++) {
            if (bith&(1<<i)) {
                H.emplace_back(i);
            }
        }
        for (int bitw=0;bitw<(1<<w);bitw++) {
            std::deque<int> W;
            for (int j=0;j<w;j++) {
                if (bitw&(1<<j)) {
                    W.emplace_back(j);
                }
            }
            for (int j=0;j<H.size();j++) {
                for (int l=0;l<w;l++) {
                    copy[H[j]][l]='o';
                }
            }
            for (int j=0;j<W.size();j++) {
                for (int l=0;l<h;l++) {
                    copy[l][W[j]]='o';
                }
            }
            int count=0;
            for (int j=0;j<h;j++) {
                for (int l=0;l<w;l++) {
                    if (copy[j][l]=='#') {
                        count++;
                    }
                    copy[j][l]=vec[j][l];
                }
            }
            if (count==k) {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}