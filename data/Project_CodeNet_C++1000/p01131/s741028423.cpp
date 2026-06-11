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

void play(string str){
    string mas[]={"x",".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int lng = 0;
    
    for(int i = 0; i < str.size() ; i++){
        if(str[i] == '0'){
            if(lng!=0){
                //cout << (lng-1) << " " << mas[str[i-1]-'0'].size() << endl;
                cout << mas[str[i-1]-'0'][(lng-1)%mas[str[i-1]-'0'].size()];
                lng = 0;
            }
        }
        else lng++;
    }
    cout << endl;
}

main(){
    //freopen("2006-input.txt","r",stdin);
    //freopen("test.txt","w",stdout);
    
    int t;
    string str;
    
    cin >> t;
    
    while(t--){
        cin >> str;
        
        play(str);
    }
    #ifdef GEREL
        for(;;);
    #endif

    return 0;
}