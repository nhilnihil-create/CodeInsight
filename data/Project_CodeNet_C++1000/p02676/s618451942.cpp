#include<bits/stdc++.h>
using namespace std;

int main(){
    int k; 
    string s;
    
    cin >> k >> s;
    
    if(s.size()>k){
        for(int i = 0; i < k; i++){
            cout << s[i];
        }
        cout<<"...\n";
    }else{
        cout << s <<"\n";
    }


}