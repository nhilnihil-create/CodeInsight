#include <iostream>
using namespace std;

int main()
{
    int N, val, left = 400, right = 600;
    cin>>N;
    val = 8;
    while(true)
    {
        if(left<=N && N<right)
        {
            cout<<val;
            break;
        }
        else
        {
            left+=200;
            right+=200;
            val-=1;
        }
    }
}
