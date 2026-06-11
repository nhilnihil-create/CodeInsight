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

queue <int> deck,temp,tempp;

void shuffle(int x,int c){
    while(x--){
        temp.pp(deck.front());
        deck.pop();
    }
    while(c--){
        tempp.pp(deck.front());
        deck.pop();
    }
    while(temp.size()){
        tempp.pp(temp.front());
        temp.pop();
    }
    while(deck.size()){
        tempp.pp(deck.front());
        deck.pop();
    }
    while(tempp.size()){
        deck.pp(tempp.front());
        tempp.pop();
    }
}

void init(int n){
    while(deck.size()) deck.pop();
    
    for(int i = n ; i >= 1 ; i--) deck.pp(i);
}
main(){
    int n,r;
    int a,b;
    
    while(cin >> n >> r){
        if(n == 0) break;
    
        init(n);
        
        while(r--){
            cin >> a >> b;
            shuffle(a-1,b);
        }
        
        cout << deck.front() << endl;
    }
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}