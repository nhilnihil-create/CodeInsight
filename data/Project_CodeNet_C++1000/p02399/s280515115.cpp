#include <iostream>
#include <iomanip>
using namespace std;
#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,j) for(int i=0;i<j;i++)

int main(void){

   long double a,b;

    cin >> a >> b;

    unsigned int z1 = a / b;
    unsigned int z2 = int(a) % int(b);
    long double z3 = a / b;

    cout << z1 << " " << z2 << " ";
    cout << fixed << setprecision(5) << z3 << endl;

    return 0;
}