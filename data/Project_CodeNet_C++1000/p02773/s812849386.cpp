#include <bits/stdc++.h>
#include <map>
using namespace std;
int main(void){
    int n;
    cin >> n;
    
    map<string,int> count;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        
        count[s]+=1;
    }
    
        int max_count = 0;
    for(const auto&x:count){
        int maxv = x.second;
        if(max_count < maxv) max_count = maxv;
    }
    
    for(auto i=count.begin();i!=count.end();i++){
        if(i->second == max_count){
            cout << i->first << endl;
        }
    }
    return 0;
}
