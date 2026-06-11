#include <iostream>

using namespace std;

int main()
{
    int n;
    long long int a,b,d;
    cin >> n >> d;
    int cn{0};
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        if((a*a)+(b*b)<=d*d)
            cn++;
    }
    cout << cn << '\n';
    return 0;
}
