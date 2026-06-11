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

void play(int n,int m,int p){
    int mas[105];
    int sum=0;
    
    for(int i = 1 ; i <= n ; i++){
        cin >> mas[i];
        sum+= mas[i];
    }
    
    sum*=100;
    
    sum = sum - (sum/100)*p;
    
    if(mas[m] == 0) cout << "0" << endl;
    else cout << int(double(sum)/double(mas[m])) << endl;
}
main(){
    int n,m,p;
    
    while(cin >> n >> m >> p){
        if(n == 0) break;
        play(n,m,p);
    }
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}