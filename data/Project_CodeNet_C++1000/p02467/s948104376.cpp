#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n; cout << n << ":";
    int i = 2;
    while(n != 1){ 
        if(n % i == 0){
            n /= i;
            cout << " " << i;
        }
        else if (n < i * i) //nが大きい素数である場合がありO(√n)が最適解
        {
            cout << " " << n;
            break;
        }
        else
        {
            i++;
        }
    }
    cout << endl;
    return 0;
}
