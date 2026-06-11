#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
#include <numeric> //accumulate
using namespace std;

int main(){
    cout << fixed << setprecision(6);
    int h,n; cin >>h>> n;
    vector<int> o(n);
    for (int i = 0; i < n; i++)
    {
        cin >> o[i];
    }
    if(h <= accumulate(o.begin(),o.end(),0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}