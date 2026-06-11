#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define ll long long int
#define mod 1000000007

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    if(2 * b >= a)
    cout << 0;
    else
    cout << a - 2 * b;
}







