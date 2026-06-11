//ITP 1_10_A
#include <iostream>
#include<cmath>

//ctudio

using namespace std;

//lf==line feed
//0.8lf?

int main()
{
    double x1,x2,y1,y2,val,val2;
    cin >> x1 >> y1 >> x2 >> y2;
    val=((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
    val2 = sqrt(val);
    
    printf("%0.8lf\n",val2);
    
    return 0;
}

