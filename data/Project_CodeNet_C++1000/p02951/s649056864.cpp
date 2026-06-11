#include <iostream>
#include <map>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int result=c-(a-b);
    if(result <=0){
        result =0;
    }
    cout << result;
    return 0;
}
