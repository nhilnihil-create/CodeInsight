#include <bits/stdc++.h>
using namespace std; 

int main(){
int N, A, B, C, D;
cin >> N >> A >> B >> C >> D;
string S;
cin >> S;

// S.at(A - 1) = 'A';
// S.at(B - 1) = 'B';
bool flag = true;
bool flag2 = false;
for(int i = 0; i < N; i++){ 
     if (i > A - 1 && i < C - 1) {
         if(S.at(i) == '#' && S.at(i + 1) == '#') {
             flag = false;
             break;
         }
     }    
     if (i > B - 1 && i < D - 1) {
         if(S.at(i) == '#' && S.at(i + 1) == '#') {
             flag = false;
             break;
         }
     }
     if (C > D && i > B - 3 && i < min(C, D) - 1){
         if(S.at(i) ==  '.' && S.at(i + 1) ==  '.' && S.at(i + 2) ==  '.' )
         flag2 = true;
     }
    

     }  


if(C < D) flag2 = true;
// cout << flag << flag2 << endl;

if(flag && flag2){
    cout << "Yes" << endl;
}else{
    cout << "No" << endl;
}


}
