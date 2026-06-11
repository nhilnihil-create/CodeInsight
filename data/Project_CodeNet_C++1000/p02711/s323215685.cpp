#include <bits/stdc++.h>
using namespace std;

int main(){
    int A;
    cin >> A;
    if((A-7) % 10 == 0){
        cout << "Yes" << endl;
    }
    else if(((A/10)-7)%10 == 0){
        cout << "Yes" << endl;
    }
    else if(A/100 == 7){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}