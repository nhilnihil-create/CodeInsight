#include<iostream>
using namespace std;

const int N_MAX = 105;

int main(){
    int n;
    cin >> n;
    bool ans = true;
    for(int i = 0; i < n; i++){
        int A;
        cin >> A;
        if (A % 2 == 0){
            if (A % 3 != 0 && A % 5 != 0)ans = false;
        }
    }
    if (ans)cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;
    return 0;
}