#include <iostream>

using namespace std;

int main(){
    char name[4];
    cin >> name;
    for (int i=0;i<3;++i){
        if (name[i] == name[i+1]){
            cout << "Bad\n";
            return 0;
        }
    }
    cout << "Good" << "\n";
    return 0;
}

