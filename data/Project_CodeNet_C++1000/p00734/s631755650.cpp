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

void play(int n,int m){
    int a[105]={0} , b[105]={0};
    int aa = 0 , bb = 0;
    int q;
    
    for(int i = 0 ; i < n ; i++){
        cin >> q;
        a[q]++;
        aa+=q;
    }
    
    for(int i = 0 ; i < m ; i++){
        cin >> q;
        b[q]++;
        bb+=q;
    }
    
    for(int i = 0 ; i < 103 ; i++){
        if(a[i]){
            int dif = bb+2*i-aa;
            if(dif >=0 && dif%2==0 && dif <=200 && b[dif/2]){
                cout << i << " " << dif/2 << endl;
                return;
            }
        }
    }
    
    cout << "-1" << endl;
}

main(){
    //freopen("1153-input.txt","r",stdin);
    int n,m;
    
    while(cin >> n >> m){
        if(n == 0) break;
        
        play(n,m);
    }
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}