#include <iostream>
 
using namespace std;
 
int main () {
    int D,T,S;
    while(cin>>D>>T>>S) {
        int ans = S * T;
        if (ans >= D) {
            cout << "Yes"<<endl;
        } else {
            cout << "No"<<endl;
        }
    }
}