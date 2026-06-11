#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

int main(void)
{
    int n; scanf("%d", &n);
    std::vector<double> value(n);
    for (int i=0; i<n; i++) scanf("%lf", &value.at(i));

    std::sort(value.begin(), value.end());

    for (int i=0; i<n-1; i++)
    {
        value.at(i+1) = (value.at(i)+value.at(i+1))/2.0;
    }

    printf("%lf\n", value.at(n-1));
}