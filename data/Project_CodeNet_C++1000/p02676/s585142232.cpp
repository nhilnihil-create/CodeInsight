#include<bits/stdc++.h>
using namespace std;

int main(){
    int K;
    cin >> K;

    string S ,T;
    cin >> S;

    if(S.size()<K|| S.size()==K){
        cout << S <<endl;
    }else{
        for(int i=0; i<K; i++){
            T+=S.at(i);
        }
        cout << T << "..." << endl;
    }
}