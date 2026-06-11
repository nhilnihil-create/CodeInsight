#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int can = 0;
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(i*j==N) can = 1;
        }
    }
    if(can==1) cout << "Yes" << endl;
    else cout << "No" << endl;
} 