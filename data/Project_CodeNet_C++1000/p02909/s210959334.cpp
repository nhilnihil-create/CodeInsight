#include <iostream>
#include <string>
using namespace std;

int main (void){
    string weather;
    cin >> weather;
    if (weather == "Sunny"){
        cout << "Cloudy" << endl;
    }else if(weather == "Cloudy"){
        cout << "Rainy" << endl;
    }else{
        cout << "Sunny" << endl;
    }
    return 0;
}

