#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    ll a, b, c, d;
    std::cin >> a >> b >> c >> d;

    ll max_num = -1000000000000000000;

    max_num = (max_num > (a*c)) ? max_num : (a*c);
    max_num = (max_num > (a*d)) ? max_num : (a*d);
    max_num = (max_num > (b*c)) ? max_num : (b*c);
    max_num = (max_num > (b*d)) ? max_num : (b*d);
    
    std::cout << max_num << std::endl;
}