#include <iostream>
#include <vector>
#include <iomanip>

#include <stdlib.h>
#include <math.h>

using namespace std;

long double MinkowskiDistance(const vector<int> &v1, const vector<int> &v2, const int p)
{

    long double ret = 0;
    size_t N = v1.size();

    if(p==-1)
    {
        for(size_t i = 0; i < N; i++)
        {
            ret = max(ret, (long double)abs(v1[i] - v2[i]));
        }
    }
    else
    {
        for(size_t i = 0; i < N; i++)
        {
            ret += pow((long double)abs(v1[i] - v2[i]), (long double)p);
        }
        ret = pow(ret, 1.0 / (long double)p);
    }


    return ret;


}


int main()
{
    int n;
    cin >> n;

    vector<int> v1(n,0), v2(n,0);
    for(int i = 0; i < n; i++){ cin >> v1[i]; }
    for(int i = 0; i < n; i++){ cin >> v2[i]; }

    cout << fixed << setprecision(6);
    cout << MinkowskiDistance(v1, v2,  1) << endl;
    cout << MinkowskiDistance(v1, v2,  2) << endl;
    cout << MinkowskiDistance(v1, v2,  3) << endl;
    cout << MinkowskiDistance(v1, v2, -1) << endl;

    return 0;
}