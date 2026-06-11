#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int A,B,C,D,i=0;
    cin >> A >> B >> C >> D;
    while(1){
        if(i %2 ==0){
            C-=B;
            if(C <=0){
                cout << "Yes" <<endl;
                break;
            }
        }
        else{
            A-=D;
            if(A <=0){
                cout << "No" <<endl;
                break;
            }
        }
        i++;
    }
    
}