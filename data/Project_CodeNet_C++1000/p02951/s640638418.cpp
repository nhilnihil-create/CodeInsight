#include <iostream>
using namespace std;
int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(c-(a-b),0) << endl;
}