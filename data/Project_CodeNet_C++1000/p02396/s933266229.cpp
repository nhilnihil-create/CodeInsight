#include <iostream>
using namespace std;

int main()
{
    int input_data[10000];
    int id_data = 0;

    while(1) {
        int input;
        cin >> input;
        input_data[id_data] = input;
        id_data++;
        if(input == 0) break;
    }

    for(int i = 0; i < id_data-1; i++) cout << "Case " << i+1 << ": " << input_data[i] << endl;

    return 0;
}