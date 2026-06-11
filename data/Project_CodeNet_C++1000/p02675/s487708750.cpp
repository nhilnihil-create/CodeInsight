#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int A=N%10;
    if(A==2||A==4||A==5||A==7||A==9) {
        cout << "hon" << endl;
    }
    else if(A==0||A==1||A==6||A==8) {
        cout << "pon" << endl;
    }
    else {
        cout << "bon" << endl;
    }
 
    
}
