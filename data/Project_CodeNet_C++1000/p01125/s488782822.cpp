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

int test(int n){
    int mas[40][40]={0};
    int x,y;
    int w;
    
    for(int i = 0 ; i < n ; i++){
        cin >> x >> y;
        mas[x][y]=1;
    }
    
    int m;
    int curx = 10, cury = 10;
    char d;
    
    cin >> m;
    
    while(m--){
        cin >> d >> w;
        
        if(d == 'N'){
            if((cury+w)>20) continue;
            while(w--){
                if(cury<20){
                    cury++;
                    if(mas[curx][cury]==1){
                        mas[curx][cury]=0;
                        n--;
                    }
                }
            }
        }
        
        if(d == 'E'){
            if((curx+w)>20) continue;
            while(w--){
                if(curx<20){
                    curx++;
                    if(mas[curx][cury]==1){
                        mas[curx][cury]=0;
                        n--;
                    }
                }
            }
        }
        
        if(d == 'S'){
           if((cury-w)<0) continue;
            while(w--){
                if(cury>0){
                    cury--;
                    if(mas[curx][cury]==1){
                        mas[curx][cury]=0;
                        n--;
                    }
                }
            }
        }
        
        if(d == 'W'){
            if((curx-w)<0) continue;
            while(w--){
                if(curx>0){
                    curx--;
                    if(mas[curx][cury]==1){
                        mas[curx][cury]=0;
                        n--;
                    }
                }
            }
        }
    }
    
    if(n==0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

main(){
    int n;
    
    while(cin >> n){
        if(n == 0) break;
        test(n);
    }
    
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}