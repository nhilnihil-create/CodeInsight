#include <iostream>
using namespace std;

//掛け算して切り捨て
int main(){
    long long int A;
    double B;
    cin >> A >> B;
    long long int res=B*100+0.5;
    res = (res*A)/100;

    cout << res << endl;
}