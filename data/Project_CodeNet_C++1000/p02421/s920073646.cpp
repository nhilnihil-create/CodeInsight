#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    char t[1010][111],h[1010][111];
    int n,ta = 0,ha = 0,len;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> t[i] >> h[i];
    }
    for(int i = 0;i < n;i++){
        len = max(strlen(t[i]),strlen(h[i]));
        for(int j = 0;j < len;j++){
            if(t[i][j] != h[i][j]){
                if(t[i][j] - '0' > h[i][j] - '0'){
                    ta += 3;
                    //cout << i << "ta win" << endl;
                    break;
                }
                else if(t[i][j] - '0' < h[i][j] - '0'){
                    ha += 3;
                    //cout << i << "ha win" << endl;
                    break;
                }
            }
            else if(j == len - 1 && t[i][j] - '0' == h[i][j] - '0'){
                ta++;
                ha++;
                //cout << i << "draw" << endl;
                break;
            }
        }
    }
    cout << ta << " " << ha << endl;

    return 0;
}

