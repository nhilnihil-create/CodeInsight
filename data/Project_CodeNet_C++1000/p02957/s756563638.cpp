#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
const double PI = (acos(-1));
const long long MOD = pow(10, 9) + 7;
long long kaizyou(int N);
long long POW(int J);

int main()
{
    long long int A,B;
    cin >> A >> B;
    
    long double X = (A + B)/2.0;
    long long int Y = X;

    if( Y == X)
    {
        long long int C = (A + B)/2;
        cout << C;
    }else
    {
        
        cout << "IMPOSSIBLE";
    }
    

}
