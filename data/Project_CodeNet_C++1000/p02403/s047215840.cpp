#include<iostream>
#include<stdio.h>
 using namespace std;
int main()
{
    int h, w;
    int i, j;
    cin >> h;
    cin >> w;
    while (h != 0 || w != 0){
        for (i = 0; i < h; i++){
            for (j = 0; j < w; j++){
                cout << "#";
            }
            std::cout << "\n";
        }
        cout << "\n";
        cin >> h;
        cin >> w;
    }
    return 0;
}