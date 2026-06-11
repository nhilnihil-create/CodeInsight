#include <bits/stdc++.h>

using namespace std;

int main(){
    string S,T;
    int rightPredict=0;
    cin>>S>>T;
    for(int i =0;i<=2;i+=1){
        if (S[i]==T[i]){
            rightPredict+=1;
        }
    }
    cout<<rightPredict;
}