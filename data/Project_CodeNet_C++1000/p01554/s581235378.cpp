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

main(){
    vector <string> name;
    int n,m;
    string q;
    
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >> q;
        name.pb(q);
    }
    
    cin >> m;
    
    int condition = 0;
    for(int i = 0 ; i < m ; i++){
        cin >> q;
    
        int flag = 0;    
        for(int i = 0 ; i < n ; i++){
            if(q == name[i]) flag = 1;
        }
        
        if(flag == 1){
            if(condition == 0){
                cout << "Opened by " << q << endl;
                condition = 1;
            }
            else{
                cout << "Closed by " << q << endl;
                condition = 0;
            }
        }
        else{
            cout << "Unknown " << q << endl;
        }
    }
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}