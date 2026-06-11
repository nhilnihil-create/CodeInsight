#include<iostream>
using namespace std;

int main()
{
    static char num[5];
    int i, sum;
    
    do{
        cin >> num;
        sum = 0;
        for(i = 0; *(num + i); i++){
            sum = sum + static_cast<int>(*(num + i) - '0');
		}
        if(sum == 0) break;
        cout << sum << endl;
    }while(1);

    return 0;
}