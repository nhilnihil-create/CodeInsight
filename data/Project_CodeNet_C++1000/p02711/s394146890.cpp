#include<iostream>
using namespace std;

int main(void){
    int N;
    bool result{false};

    cin >> N;

    if(N/100==7){
        result = true;
    }
    else if(N%100/10==7){
        result = true;
    }
    else if(N%10==7){
        result = true;
    }
    
    if(result){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}
