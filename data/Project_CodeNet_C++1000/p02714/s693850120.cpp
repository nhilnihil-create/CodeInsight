#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int rgb[n][3] = {};
    //個数をカウント
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            rgb[i][0]++;
        }else if(s[i] == 'G'){
            rgb[i][1]++;
        }else{
            rgb[i][2]++;
        }
    }
    //i個時点での総数を計算する
    for(int i = 1; i < n; i++){
        rgb[i][0] += rgb[i-1][0];
        rgb[i][1] += rgb[i-1][1];
        rgb[i][2] += rgb[i-1][2];
    }
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        char x = s[i];
        for(int j = i+1; j < n; j++){
            char y = s[j];
            if(s[i] == 'R' && s[j] == 'B'){
                cnt += rgb[n-1][1] - rgb[j][1];
                if(s[2*j-i] == 'G'){
                    cnt--;
                }
            }else if(s[i] == 'R' && s[j] == 'G'){
                cnt += rgb[n-1][2] - rgb[j][2];
                if(s[2*j-i] == 'B'){
                    cnt--;
                }
            }else if(s[i] == 'B' && s[j] == 'R'){
                cnt += rgb[n-1][1] - rgb[j][1];
                if(s[2*j-i] == 'G'){
                    cnt--;
                }
            }else if(s[i] == 'B' && s[j] == 'G'){
                cnt += rgb[n-1][0] - rgb[j][0];
                if(s[2*j-i] == 'R'){
                    cnt--;
                }
            }else if(s[i] == 'G' && s[j] == 'B'){
                cnt += rgb[n-1][0] - rgb[j][0];
                if(s[2*j-i] == 'R'){
                    cnt--;
                }
            }else if(s[i] == 'G' && s[j] == 'R'){
                cnt += rgb[n-1][2] - rgb[j][2];
                if(s[2*j-i] == 'B'){
                    cnt--;
                }
            }   
        } 
    }
    cout << cnt << endl;
    //cout << rgb[n-1][0] << " " << rgb[n-1][1] << " " << rgb[n-1][2] << endl;

    return 0;
}