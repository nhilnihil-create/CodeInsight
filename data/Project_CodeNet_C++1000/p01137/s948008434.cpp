#include <iostream>
using namespace std;

int main()
{
    int e;
    int x;
    while(1){
        cin >> e;
        int sum = e;
        if(e == 0){
            break;
        }
        for(int z = 0; z * z * z <= e; z++){
            for(int y = 0; z * z * z + y * y <= e; y++){
                x = e - (z * z * z + y * y);
                if(x + y + z < sum){
                    sum = x + y + z;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}