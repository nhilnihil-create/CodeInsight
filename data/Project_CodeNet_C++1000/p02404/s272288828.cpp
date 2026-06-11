/* 未完成 */
#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main(void){
    int h,w,i,j,k;    

    while (1){
        cin >> h >> w;
        if (h == 0 && w == 0) break;

    for (int i = 0; i < w; ++i)
    {
        cout << "#";
    }

    cout << endl;
    
    for (int i = 0; i < h-2; ++i)
    {
        cout << "#";
        for (int j = 0; j < w-2; ++j)
        {
            cout << ".";
        }
        cout << "#" << endl;
    }
    for (int k = 0; k < w; ++k)
    {
        cout << "#";
    }

    cout << endl;
    cout << endl;
}
    return 0;

}