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

int play(int n,int m){
    int me[55]={0};
    int cur=0;
    int left = m;
    
    while(1){
        if(cur == n) cur = 0;
        
        if(left == 1 && me[cur] == (m-1)) return cur;
        
        if(left == 0){
            left = me[cur];
            me[cur] = 0;
        }
        else{
            left--;
            me[cur]++;
        }
        
        cur++;
    }
}
main(){
    int n,m;
    
    while(cin >> n >> m){
        if(n == 0) break;
        cout << play(n,m) << endl;
    }
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}