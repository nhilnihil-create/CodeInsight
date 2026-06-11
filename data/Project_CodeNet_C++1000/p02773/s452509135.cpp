#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,m;
    string s;
    
    m = 0;
    s = "";
    
    cin >> N;
    map<string,int> dic;

    for(int i = 0; i < N; i++){
        cin >> s;
        
        dic[s] += 1;
        
        m = max(m,dic[s]);
    }
    
    for(auto it = dic.begin(); it != dic.end(); it++){
        if(m == it->second){
            cout << it->first << endl;
        }
    }
    
    return 0;
}
  