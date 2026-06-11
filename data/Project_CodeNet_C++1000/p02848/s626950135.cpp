#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    string S;
    cin >> N >> S;
    
    vector<char> A;
    for(char c = 'A' ; c <= 'Z' ; c++){
        A.push_back(c);
    }
    
    for(int i = 0 ; i < S.size() ; i++){
        for(int j = 0 ; j < 26 ; j++){
            if(S.at(i) == A.at(j)){
                if(j+N >= 26){
                    cout << A.at(j+N -26);
                }
                else{
                    cout << A.at(j+N);
                }
            }
        }
    }
}