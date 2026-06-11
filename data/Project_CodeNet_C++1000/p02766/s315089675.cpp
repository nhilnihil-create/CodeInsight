#include <iostream>
using namespace std;

int n, k;

int main(void)
{
    cin >> n >> k;

    int cnt=0;
    while (n>0){
        n = n/k;
        cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}
