#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e];

//beginner 1999 129

int h, w;

string s[e];

ll row[3000][3000], col[3000][3000], another_col[3000][3000], another_row[3000][3000];

int main()
{
    cin >> h >> w;
    for(int i=1; i<=h; i++){
        cin >> s[i];
        s[i] = ' ' + s[i];
        for(int j=1; j<=w; j++){
            row[i][j] = row[i][j-1];
            if(s[i][j] == '#'){
                row[i][j] = 0;
            }
            else{
                row[i][j] ++;
            }
        }
        for(int j=w; j>=1; j--){
            another_row[i][j] = another_row[i][j+1];
            if(s[i][j] == '#'){
                another_row[i][j] = 0;
            }
            else{
                another_row[i][j] ++;
            }
        }
    }
    for(int j=1; j<=w; j++){
        for(int i=1; i<=h; i++){
            col[i][j] = col[i-1][j];
            if(s[i][j] == '#'){
                col[i][j] = 0;
            }
            else{
                col[i][j] ++;
            }
        }
        for(int i=h; i>=1; i--){
            another_col[i][j] = another_col[i+1][j];
            if(s[i][j] == '#'){
                another_col[i][j] = 0;
            }
            else{
                another_col[i][j] ++;
            }
        }
    }
    ll maxx = 0;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(s[i][j] == '#') continue;
            if(row[i][j] + col[i-1][j] + another_col[i+1][j] + another_row[i][j+1] > maxx){
                maxx = row[i][j] + col[i-1][j] + another_col[i+1][j] + another_row[i][j+1];
                //cout << i <<" "<<j<<"\n";
            }
        }
    }
    cout << maxx;
}
