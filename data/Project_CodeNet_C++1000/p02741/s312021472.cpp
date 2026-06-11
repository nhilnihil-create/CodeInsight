#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int input[33] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int k;
    cin >> k;
    cout << input[k-1]<<endl;
}


