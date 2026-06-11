#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    int n; scanf("%d", &n);
    std::vector<int> a(n+1), b(n);
    long long count = 0;

    for (int i=0; i<n+1; i++) scanf("%d", &a.at(i));
    for (int i=0; i<n; i++)   scanf("%d", &b.at(i));

    for (int i=n-1; i>=0; i--)
    {
        if (a.at(i+1) <= b.at(i))
        {
            count += a.at(i+1);
            b.at(i) -= a.at(i+1);
            a.at(i+1) = 0;
        }
        else
        {
            count += b.at(i);
            a.at(i+1) -= b.at(i);
            b.at(i) = 0;
        }
        
        if (a.at(i) <= b.at(i))
        {
            count += a.at(i);
            b.at(i) -=  a.at(i);
            a.at(i) = 0;
        }
        else 
        {
            count += b.at(i);
            a.at(i) -= b.at(i);
            b.at(i) = 0;
        }
        //std::cout << count << std::endl;
    }

    std::cout << count << std::endl;
}