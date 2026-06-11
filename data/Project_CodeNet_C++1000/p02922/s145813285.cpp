#include<iostream>
#include<vector>
 
using namespace std;

int main()
{
    int n, k, soc= 1, count = 0;

    cin >> n >> k;

    while(soc < k)
    {
        soc = soc - 1 + n;
        count++;
    }

    cout << count;
}