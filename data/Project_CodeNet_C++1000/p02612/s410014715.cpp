#include <iostream>
using namespace std;
int main()
{
    int N,A,B,i,m;
    cin >> N;
    A=1000;
    i = N/A;
    if(N%A){
        if(N>A) {
        B = A * (i+1);
        m = B - N;
        cout << m << endl;
        }
        else {
            m = A - N;
            cout<< m << endl;
        }
    }
    else if(N/A) cout << 0 << endl;

    return 0;
}