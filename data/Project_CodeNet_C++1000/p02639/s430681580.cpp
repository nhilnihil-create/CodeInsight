#include<bits/stdc++.h>

using namespace std;

int main(){
    int niz[5];
    int rj;
    for(int i=0;i<5;i++){
        cin>>niz[i];
        if(niz[i]==0){
            rj=i+1;
        }
    }
    cout <<rj<<endl;
}
