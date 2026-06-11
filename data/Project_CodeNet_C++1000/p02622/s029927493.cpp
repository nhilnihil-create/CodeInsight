#include<iostream>

using namespace std;

int main(){
    string s,t;
    cin >> s;
    cin >> t;
    if(s.size() != t.size()){
        return 0;
    }else{
        int cnt = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] != t[i]){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    
}