#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    char in[500];
    int ans_max=0,ans_long=0;
    string s_max,s_long;
    map<string,int> mm;
    
    while(EOF!=scanf("%s",in)){
        
        string S = in;
        
        if((int)S.size() > ans_long){
            s_long = S;
            ans_long = (int)S.size();
        }
        
        mm[S]++;
    }
    
    for(map<string,int>::iterator it = mm.begin();it!=mm.end();it++){
        if( (it->second) > ans_max ){
            ans_max = it->second;
            s_max = it->first;
        }
    }
    
    cout << s_max <<  " " << s_long << endl;
    
    return 0;
}