#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    for(int i=0;i<h;i++)for(int j=0;j<w;j++) cin >> s[i][j];

    vector<vector<pair<int, int>>> vec(h, vector<pair<int, int>>(w, {0,0}));

    for(int i=0;i<h;i++){
        int count = 0;
        bool flag = false;
        for(int j=0;j<w;j++){
            if(s[i][j] == '.'){
                if(flag) count++;
                else{
                    flag = true;
                    count++;
                }
                if(j==w-1){
                    for(int k=j-count+1;k<=j;k++) vec[i][k].first = count;
                    flag = false;
                    count = 0;
                }
            }else{
                if(flag){
                    for(int k=j-count;k<j;k++) vec[i][k].first = count;
                    flag = false;
                }
                count = 0;
            }
        }
    }

    for(int j=0;j<w;j++){
        int count = 0;
        bool flag = false;
        for(int i=0;i<h;i++){
            if(s[i][j] == '.'){
                if(flag) count++;
                else{
                    flag = true;
                    count++;
                }
                if(i==h-1){
                    for(int k=i-count+1;k<=i;k++) vec[k][j].second = count;
                    flag = false;
                    count = 0;
                }
            }else{
                if(flag){
                    for(int k=i-count;k<i;k++) vec[k][j].second = count;
                    flag = false;
                }
                count = 0;
            }
            
        }
    }

    int ans = 0;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++) ans = max(ans, vec[i][j].first + vec[i][j].second - 1);


    cout << ans << endl;
}