#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;


int main(){
    long long int n, i, index = 0, input, temp;
    vector<int> v1;
    cin >> n;

    for(i = 1; i <= sqrt(n); i++){
        if(n%i == 0){
            input = i;
            v1. push_back(input);
            index++;
        }

    }
    temp = n/ v1[index-1];

    if(v1[index-1] == 1)
        cout << n - 1  << endl;

    else
        cout << (temp+v1[index-1]) - 2  << endl;


    return 0;
}
