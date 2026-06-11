
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;


double calStandardDeviation(const vector<double> &pts)
{
    double sum = 0;
    for(const auto& x : pts)
    {
        sum += x;
    }
    double ave = sum / pts.size();

    sum = 0;
    for(const auto& x : pts)
    {
        sum += pow(x - ave, 2);
    }

    return sqrt(sum / pts.size());

}

int main()
{
    double n;
    vector<double> vec;

    while(true)
    {
        cin >> n;
        if(n==0){ break; }

        vec.clear();
        for(int i = 0; i< n; i++)
        {
            double tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        cout << fixed << setprecision(8);
        cout << calStandardDeviation(vec) << endl;

    }

    return 0;
}