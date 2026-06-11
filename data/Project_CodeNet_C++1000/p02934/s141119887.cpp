#include <iostream>
using namespace std;

int main(){
    int N;
    double sum = 0;
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        double num;
        cin >> num;
        sum = sum + (1/num);
    }

    cout << (1/sum) << endl;
}