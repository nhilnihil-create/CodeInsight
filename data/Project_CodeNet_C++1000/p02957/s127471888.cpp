#include <iostream>

using namespace std;

int main()
{
    long long a , b , k , t1 , t2;
    cin >> a >> b;
    if ((a + b) % 2 == 0){
        cout << (a + b) / 2;
    }else{
        cout << "IMPOSSIBLE";
    }
    return 0;
}
