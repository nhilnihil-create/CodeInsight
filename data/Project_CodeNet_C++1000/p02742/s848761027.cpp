#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    long long int h, w;
    long long int result;
    cin >> h >> w;
    if (h == 1 || w == 1) {
        result = 1;
    }
    else {
        result = (h * w + 1) / 2;
    }
    
    cout << result << endl;
    
    //getline(cin, str);
    //vector < vector < int > > A(x, vector(y, 0));
    //int avg = round((float)accumulate(X.begin(), X.end(), 0.0) / N);
    return 0;
}