#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    double data,sum,mean,std;
    int n;

    while(1){
        cin >> n;
        if(n==0) break;
        sum = 0;
        mean = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> data;
            sum += data*data/n;
            mean += data/n;
        }
        std = sqrt(sum - mean*mean);

        printf("%lf\n", std);

    }
    return 0;
}