#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;

const int INF = INT_MAX/3;

int main(){
    int H, W;
    cin >> H >> W;
    while(H!=0 || W!=0){
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cout << "#" ;
            }
            cout << endl ;
        }
        cout << endl;
        cin >> H >> W;
    }
    return 0;
}