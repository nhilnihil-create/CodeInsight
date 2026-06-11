#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N;
    string S;
    cin>>N>>S;
    bool judge=true;
    if(N%2==1){
        cout<<"No"<<endl;
    }
    else{
        rep(i,N/2){
            if(S[i]!=S[N/2+i]){
                judge=false;
                break;
            }
        }
        if(judge==false){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
  
   
}


