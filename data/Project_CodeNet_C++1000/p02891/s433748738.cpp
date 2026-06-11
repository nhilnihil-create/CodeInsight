#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;
    ll K;
    cin >> K;
    ll siz=S.size();
    ll X=0;
    ll counter=0;
    for(ll i=0;i<siz-1;i++){
        if(S.at(i)==S.at(i+1)){counter++;
        }
        else{
            X+=(counter+1)/2;
            counter=0;
        }
    ;}
    X+=(counter+1)/2;
    if(counter==siz-1){
        cout<<(siz*K)/2;
    }
    else if(S.at(0)!=S.at(siz-1)){
        cout<<X*K<<endl;
    }
    else if(S.at(0)==S.at(siz-1)){
        ll counterf=0;
       for(int i=0;i<siz;i++){if(S.at(i)==S.at(i+1)){counterf++;
        }
        else{break;}
       ;}
       ll Y=X*K-((counter+1)/2)*(K-1)-((counterf+1)/2)*(K-1)+(counter+counterf+2)/2*(K-1);
       cout<<Y<<endl;
       
    }
    
    return 0;
}  
