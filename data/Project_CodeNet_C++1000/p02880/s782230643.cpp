#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    int n; cin >> n;
    int yes=0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if(i*j==n) yes++;
        }
        
    }
    if(yes) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}