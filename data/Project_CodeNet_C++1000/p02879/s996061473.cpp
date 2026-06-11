#include <iostream>
#include<map>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int A,B; cin >> A >> B;
    if(A < 10 && B < 10){
        fin(A*B);
    }else fin(-1);
    return 0;
}