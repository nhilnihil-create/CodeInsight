#include <iostream>

using namespace std;

int main(void)
{
    long long N;

    cin >> N;

    if(N == 2){
        cout << 0 << endl;
    }

    else if(N % 2 == 0){
        cout  <<  N/2-1 << endl;
    }

    else{
        cout <<  N/2 << endl;
    }

    return 0;
}