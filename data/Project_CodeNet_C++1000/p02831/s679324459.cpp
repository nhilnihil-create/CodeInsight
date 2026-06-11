#include <iostream>
#include <string>
using namespace std;
int main(void){
    long long A,B;
    cin >> A >> B;
    
    long long ans;
    long long X = A,Y = B;
    while(X != Y){
        if(X < Y){
            X += A;
        }
        else{
            Y += B;
        }
    }
    cout << X << endl;
}
