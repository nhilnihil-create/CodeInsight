#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int day_length;
    vector<int> values;

    cin >> day_length;
    
    for(int i = 0; i < day_length; i++){
        int v;
        cin >> v;
        values.push_back(v);
    }

    long long money = 1000;

    for(int i = 1; i < day_length; i++){
        if(values[i] > values[i - 1]){
            long long buy_count = money / values[i - 1];
            money += (long long)buy_count * (values[i] - values[i - 1]);
        }
    }

    cout << money << endl;

    return 0;
}