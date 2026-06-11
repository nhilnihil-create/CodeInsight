#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> divs(int n){
    vector<int> ret;
    for(int i = 1; i*i <= n; i++){
        if(!(n%i)){
            ret.push_back(i);
            if(n != i*i)
                ret.push_back(n/i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main()
{
    int x; cin >> x;
    int a, b;
    for(int y : divs(x)){
        a = (y+1)/2;
        b = a-y;

        while(pow(a, 5) - pow(b, 5) <= x){
            if(pow(a, 5) - pow(b, 5) == x){
                cout << a << " " << b << endl;
                return 0;
            }
            a++, b++;
        }
    }
    return 0;
}