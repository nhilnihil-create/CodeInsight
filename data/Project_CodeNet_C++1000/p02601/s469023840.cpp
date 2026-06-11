#include <iostream>

using namespace std;

int main(void)
{
    int red, green, blue;
    int mul_times;

    cin >> red >> green >> blue;
    cin >> mul_times;

    int mul_cnt = 0;
    while(red >= green){
        green *= 2;
        mul_cnt += 1;
    }

    while(green >= blue){
        blue *= 2;
        mul_cnt += 1;
    }

    if(mul_cnt <= mul_times){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}