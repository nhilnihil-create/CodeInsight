#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <string>
#define ll long double
#include <vector>
using std::vector;

using namespace std;


int main()
{
    int n, p;
    cin >> n;
    int a = 0;

    for(int i = 1; i <=n ; i++){
        cin >> p;
        if(p != i){
            a++;
        }
    }
    if(a==0 || a == 2){
        cout << "YES" << endl;
    }else
        cout << "NO" << endl;
    return 0;
}
