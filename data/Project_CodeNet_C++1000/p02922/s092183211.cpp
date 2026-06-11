#include <iostream>

using namespace std;

int get_total_sockets(int num_of_power_strips, int num_of_each_sockets)
{
    return num_of_power_strips*(num_of_each_sockets-1)+1;
}

int main()
{
    int A, B;
    cin >> A >> B;

    for(int i = 0; ; i++){
        if(B <= get_total_sockets(i, A)) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}