// 166 D

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath> 
using namespace std;

int main(){
    long long int x;
    cin >> x;
    for(int i= -118; i<=119; i++){
        for(int j= -119; j<=118; j++){
            if(pow(i, 5) - pow(j, 5) == x){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}