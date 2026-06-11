#include <iostream>
using namespace std;

int main()
{
    int input_01[255];
    int input_02[255];
    int input_id = 0;
    while(1) {
        cin >> input_01[input_id] >> input_02[input_id];
        if(input_01[input_id] == 0 && input_02[input_id] == 0) break;
        input_id++;
    }

    int draw_id = 0;
    while(draw_id < input_id) {
        for(int i = 0; i < input_01[draw_id]; i++) {
            for(int j = 0; j < input_02[draw_id]; j++) {
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
        draw_id++;
    }

    return 0;
}