#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    bool yes_flag = false;
    int count = 0;
    for(int i = 0; i < N; i++){
        int dice1, dice2;
        cin >> dice1 >> dice2;
        if(dice1 == dice2){
            count++;
            if(count == 3){
                yes_flag = true;
            }
        }else{
            count = 0;
        }
    }

    cout << ((yes_flag) ? "Yes" : "No") << endl;

}
