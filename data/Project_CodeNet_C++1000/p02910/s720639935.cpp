#include <bits/stdc++.h>
using namespace std;

string S;

int main(){
    cin>>S;
    int n=S.length();
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(S[i]=='L'){
                cout<<"No"<<endl;
                return 0;
            }
        }else if(i%2==1){
            if(S[i]=='R'){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}