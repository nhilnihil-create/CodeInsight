#include<iostream>
using namespace std;

int main(void){
    int A, B, K;
    bool result{false};
    cin >> K >> A >> B;

    if(A%K == 0){
        result = true;
    }
    else if((A/K+1)*K<=B){
        result = true;
    }

    if(result){
        cout << "OK" << endl;
    }
    else{
        cout << "NG" << endl;
    }

}
