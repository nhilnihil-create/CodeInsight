#include <iostream>
using namespace std;

int calc(double x, int price);

int main()
{
    int x, y, s;
    while(1){
        cin >> x;
        cin >> y;
        cin >> s;
        if(x == 0 && y == 0 && s == 0){
            break;
        }
        int a = 0;
        int b = 0;
        int sum;
        int max = 0;
        for(int i = 1; i < s; i++){
            for(int j = 1; j < s; j++){
                a = (i * (100 + x)) / 100;
                b = (j * (100 + x)) / 100;
                if(a + b == s){
                    sum = ((i * (100 + y)) / 100) + ((j * (100 + y)) / 100);
                    if(max < sum) {
                        max = sum;
                    }
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}