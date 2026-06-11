#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
long long n, a, b;
cin >> n >> a >> b;

long long div, sur;
div = n / (a+b);
sur = n % (a+b);
sur = min(sur, a);
cout << div*a + sur << endl;
}