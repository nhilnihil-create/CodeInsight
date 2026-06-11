#include<bits/stdc++.h>
using namespace std;

int Child_pos[100010] = { 0 };
string S;
int i, j;

int main(){
    cin >> S;

    i = 0;
    while(i < S.size()){
        char c = S[i];
        j = 0;
        while(S[i+j] == c) ++j;  //cの連続数
        if(c == 'R'){
            Child_pos[i+j-1] += (j+1)/2;
            Child_pos[i+j] += j/2;
        }else if(c == 'L'){
            Child_pos[i-1] += j/2;
            Child_pos[i] += (j+1)/2;
        }
        i += j;
    }

    for(i = 0; i < S.size(); i++) cout << Child_pos[i] << endl;

    return 0;
}