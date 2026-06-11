#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int num = 0;
    bool flag = false;
    int numberFlag = 1;

    for(int i = 0; i < N; i++){
        cin >> num;
        if(num % 2 == 0){
            if(num % 3 == 0 || num % 5 == 0){
                flag = true;
            }else{
                flag = false;
                numberFlag = -1;
            }
        }else{

        }
    }


    if(numberFlag > 0){
        cout << "APPROVED" << endl;
    }else{
        cout << "DENIED" << endl;
    }

}