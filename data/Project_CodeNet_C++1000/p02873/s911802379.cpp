#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    string S;
    cin >> S;
    vector<long long> vecl;
    long long cont = 0;
    vecl.push_back(0);
    for(int i = 0; i < S.size();i++){
        
        if(S[i]=='<'){
            cont++;
        }else{
            cont = 0;
        }
        vecl.push_back(cont);
    }
    
    // for(auto u:vecl)cout << u;
    // cout <<endl;
    
    
    vector<long long> vecr;
    cont = 0;
    vecr.push_back(0);
    for(int i = S.size()-1; i >= 0;i--){
        
        if(S[i]=='>'){
            cont++;
        }else{
            cont = 0;
        }
        vecr.push_back(cont);
    }    
    
    reverse(vecr.begin(),vecr.end());
    
    long long sum = 0;
    for(int i = 0; i < S.size() + 1;i++){
        sum += max(vecl[i],vecr[i]); 
        //cout << max(vecl[i],vecr[i])<<" "; 
    }
    cout <<endl;
    
    cout << sum <<endl;
    
}

    
    

