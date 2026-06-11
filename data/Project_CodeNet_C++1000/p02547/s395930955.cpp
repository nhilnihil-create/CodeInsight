#include <iostream>
#include <string>
using namespace std;

struct Dice{
    int one, two;
};

int main(){
    int N;
    cin >> N;
    Dice dice[N];

    for (int i = 0; i < N; ++i){
        cin >> dice[i].one >> dice[i].two;
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i){
        if (dice[i].one == dice[i].two){
            cnt += 1;
        } else{
            cnt = 0;
        }
        if (cnt == 3){
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
}