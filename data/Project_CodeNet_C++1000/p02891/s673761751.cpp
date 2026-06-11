#include <bits/stdc++.h>
using namespace std;


int main(void){
    
    string S;
    long long K;
    cin >> S >> K;
    
    long long cont = 0;
    long long contS = 0;
    long long contE = 0;

    
    if(K == 1){
        

        
        for(int i = 0; i < S.size();i++){
            if(i != S.size()-1){
                if(S[i] == S[i+1]){
                    S[i+1] = '#';
                    cont++;
                }
            }
        }
        cout << cont << endl;   
        return 0;            
    }
    

        
    if(S[0]==S[S.size()-1]){
        
        contS = 1;
        contE = 1;
            
        while(S[contS-1] == S[contS])contS++;
        while(S[S.size() - contE] == S[S.size() - contE - 1])contE++;
        
        if(S.size()==contS){
            
            if(S.size()==1){
                cout << K/2 <<endl;
                return 0;
            }
            
            if(S.size()%2==0)cout << (S.size()/2)*K <<endl;
            else{
                long long difA = S.size()/2;
                long long difB = S.size() - difA;
                //cout << difA <<" "<<difB<<endl;
                long long sum = 0;
                for(int i = 0; i < K;i++){
                    if(i%2==0)sum += difA;
                    else sum += difB;
                }
                cout << sum <<endl;
                
            } 
            return 0;
        }
    }
        
    for(int i = contS; i < S.size()-contE;i++){
        if(i != S.size()-1){
            if(S[i] == S[i+1]){
                S[i+1] = '#';
                cont++;
            }
        }else{
            if(S[0] == S[i]){
                S[0] = '#';
                cont++;
            }
        }
    }
    // cout <<contS<<endl;
    // cout <<contE<<endl;
    cout << cont * K + (contS+contE)/2*(K-1)+ contS/2+contE/2 <<endl;
    
}
