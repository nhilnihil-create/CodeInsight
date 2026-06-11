// Author :
// Date :
// Problem:
// Solution:
// Comment:

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstring>

#define pp push
#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;

int cur[1005][12][22];

main(){
    int day=1;
    int n,m,k;
    for(int i = 1 ; i <= 1000 ; i++){
        for(int j = 1 ; j <= 10 ; j++){
            if(i%3 ==0 || j%2 == 1) k = 20;
            else k = 19;
            
            for(int kk = 1 ; kk <= k ; kk++){
                cur[i][j][kk]=day;
                day++;
                //cout << i << " " << j << " " << kk << endl;
            }
        }
    }
            
    int t;
    
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cout << cur[1000][1][1]-cur[n][m][k] << endl;
    }
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}