#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int main()
{
    while(true){

        int n;
        cin >> n;
        if( n==0 ){
            break;
        }

        vector<int> s(n,0);
        for(auto&& x: s){
            cin >> x;
        }
        int sum = accumulate(s.begin(),s.end(),0);
        double avr = (1.0 *sum) / s.size();
        double sigma {0};
        for(const auto& x:s){
            sigma += (x - avr)*(x - avr);
        }
        cout << fixed << sqrt(sigma/s.size()) << endl;
    }
    return 0;
}
