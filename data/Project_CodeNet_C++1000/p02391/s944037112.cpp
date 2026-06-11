#include <iostream>
using namespace std;

void judge(){
    int a,b;
    cin >> a;
    cin >> b;
    if(a > b){
        cout <<  "a > b" << endl;
    }
    else if (a < b){
        cout << "a < b" << endl;
    }
    else{
        cout << "a == b" << endl;
    }
}
int main(int argc, const char * argv[]) {
    judge();
    return 0;
}