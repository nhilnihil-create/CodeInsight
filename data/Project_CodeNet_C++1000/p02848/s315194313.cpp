#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;

    for(int i=0; i<S.size(); i++){
        int tmp = int(S.at(i));
        if( tmp + N > int('Z') ){
            tmp = tmp - 26; 
        }
        S.at(i) = char(tmp+N);
    }

    cout << S << endl;
}
