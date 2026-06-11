#include<bits/stdc++.h>
#define ll long long
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])
#define mod 1000000007
using namespace std;

int main(){
    boostUP;

    int rows,cols;
    cin >> rows  >> cols;

    char arr[rows+1][cols+1];
    vector< vector<int> > up(rows+1,vector<int>(cols+1,0));
    vector< vector<int> > left(rows+1,vector<int>(cols+1,0));

    vector< vector<int> > right(rows+2,vector<int>(cols+2,0));
    vector< vector<int> > down(rows+2,vector<int>(cols+2,0));
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= cols; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= cols; j++){
            if(arr[i][j] == '.'){
                up[i][j] = up[i-1][j] + 1;
                left[i][j] = left[i][j-1] + 1;
            }
        }
    }
    for(int i = rows; i >=1; i--){
        for(int j = cols; j >= 1; j--){
            if(arr[i][j] == '.'){
                right[i][j] = right[i][j+1] + 1;
                down[i][j] = down[i+1][j] + 1;
            }
        }
    }
    int maxSquares = 0;
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= cols; j++){
            maxSquares = max(maxSquares, (up[i][j] + down[i][j] + right[i][j] + left[i][j]) );
        }
    }
    cout << maxSquares-3 << "\n";
//    #..#..
//    .....#
//    ....#.
//    #.#...

}

