#include <cstdlib>
#include <iostream>
#include<algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <ctime>
#include <deque>
#include <list>
#include<forward_list>
#include<set>
int main()
{
    int n, pg = 1, k;
    std :: cin >> n;
    for(int i = 1; i < n; i++)
    {
        if(i % 2 == 0)
            pg++;
        else
            continue;
    }
    std :: cout << pg;
}   
