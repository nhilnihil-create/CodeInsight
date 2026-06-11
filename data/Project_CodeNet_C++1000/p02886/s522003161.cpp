#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    cout << fixed << setprecision(6);
    int n; cin >> n;
    vector<int> o(n);
    for (int i = 0; i < n; i++)
    {
        cin >> o[i];
    }
    int sum=0;
    for (int i = 0; i <n; i++)
    {

        for (int j = i+1; j < n; j++)
        {
            sum+=o[i]*o[j];
        }
        
    }
    cout << sum << endl;
    
    return 0;
}