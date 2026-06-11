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
int cnt[1005]={0};

main(){
    for(int i = 1 ; i <= 1000 ; i++){
        for(int j = i+1 ; j <= 1000 ; j++){
            int sum = 0;
            for(int k = i ; k <= j ; k++){
                sum+=k;
            }
            if(sum<=1001) cnt[sum]++;
        }
    }
    
    int t;
    
    while(cin >> t){
        if(t == 0) break;
        cout << cnt[t] << endl;
    }
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}