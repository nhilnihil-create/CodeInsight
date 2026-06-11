#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    long long int N;
    cin >> N;
    long long int mod;
    cin >> mod;
    long long int remainder = N % mod;
    cout << to_string(min(remainder, abs(remainder - mod))) << endl;
}