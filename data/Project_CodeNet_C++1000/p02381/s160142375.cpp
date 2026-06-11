#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        cin >> n;
        if(n == 0)
        {
            return 0;
        }
        vector<int> vs;
        long int sum = 0;
        for(int i = 0;i < n;i++)
        {
            int s;
            cin >> s;
            sum += s;
            vs.push_back(s);
        }
        double av = (double)sum / n;
        double a = 0;
        for(vector<int>::iterator itr = vs.begin();itr != vs.end();itr++)
        {
            a += (*itr - av) * (*itr - av);
        }
        a = (double)a / n;
        cout << setprecision(8) << fixed << sqrt(a) << endl;
    }
}