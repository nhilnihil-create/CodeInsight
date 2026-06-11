#include<iostream>
#include<utility>
#include<string>
#include<vector>
#define ll long long
using namespace std;

int main(){
    int N;
    string S;
    cin>>N>>S;
    ll Rn=0,Gn=0,Bn=0;


    for(int i=0;i<N;i++){
        if(S[i]=='R'){
            Rn++;
        } 
        else if(S[i]=='G'){
            Gn++;
        }
        else if(S[i]=='B'){
            Bn++;
        }
    }
    ll comn=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(2*j-i<N){
                if(S[i]!=S[j]&&S[i]!=S[2*j-i]&&S[j]!=S[2*j-i]){
                    comn++;
                }
            }
            
        }    
    }
    
    cout<<Rn*Bn*Gn-comn<<endl;
    return 0;
}