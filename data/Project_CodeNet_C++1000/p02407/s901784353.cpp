#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int cases, num[200];
    cin >> cases;
    for(int i = 0; i < cases; ++i){
        cin >> num[i];
    }
    for(int i = cases - 1; i >= 0; --i){
        if(i != 0){
        cout << num[i] << " ";
        }
        else{
            cout << num[i];
        }
    }
    cout << endl;
}