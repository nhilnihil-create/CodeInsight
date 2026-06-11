#include <iostream>
using namespace std;

int main(){
    int k;cin>>k;
    int a,b;cin>>a>>b;
    if (a % k == 0 || b % k == 0){
        cout << "OK" << endl;
    } else {
        if (a / k - b / k == 0){
            cout << "NG" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
}