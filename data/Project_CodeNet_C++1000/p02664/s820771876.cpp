#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
int main(void){
 
        string T;
 
        cin>>T;
 
        rep(i,T.length()){
                if(T[i]=='?'){
                        T[i]='D';
                }
        }
        cout<<T<<endl;
          return 0;
}