#include<iostream>
using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;
    int min, max;
    long sum;
    min = max = sum = a;

    while(cin >> a){
        if(min > a) min = a;
        if(max < a) max = a;
        sum = sum + a;
    }
    cout << min << " " << max << " " << sum << endl;

    return 0;
}