#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N;
    cin>>N;
    bool judge=false;
    
    rep(i,9){
        if(N%(9-i)==0&&N/(9-i)<=9){
            judge=true;
            break;
        }
    }
    if(judge==true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
   
}


