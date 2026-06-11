#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    int n ; 
    cin >> n ;
    int count = 0 ;
    for(int i = 1 ; i < n +1 ; i++){
        if(n - i > 0 && i != n-i){
            count ++ ;
        }
    }
    cout << count / 2 << endl;
    return 0;
}