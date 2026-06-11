#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

void Solution()
{
    double x1, y1, x2, y2;
    
    cin>>x1>>y1>>x2>>y2;
    
    cout<<fixed<<setprecision(5)<<sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))<<endl;
}

int main()
{
    Solution();
    return 0;
}