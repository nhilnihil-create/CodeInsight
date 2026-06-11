#include <iostream>
using namespace std;
int main(){
    int n;
    string color;
    cin >> n;
    cin >> color;

    if (n >= 3200){
        cout << color << endl;
    }
    else{
        cout << "red" << endl;
    }
}
