#include <iostream>
#include <string>
using namespace std;
int min(int a,int b){
    return a < b ? a : b;
}

int main(void){
    string S;
    cin >> S;
    int N = S.length();
    bool is_kaibun = true;
    int middle = (N-1) / 2;
    for(int i=0;i < middle;i++){
        if(S[i] != S[N-i-1]){
            is_kaibun = false;
        }
    }
    
    
    for(int i=0;i < middle / 2;i++){
        if(S[i] != S[middle-i-1] || S[middle+i+1] != S[N-i-1]){
            is_kaibun = false;
        }
    }
    if(is_kaibun){
        cout << "Yes";
    }
    else{
        cout <<"No";
    }
}
