#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll S, temp;
int main()
{
    std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    cin >> S;
    if (S <= 1000000000)
    {
        cout << S << " 0 0 0 0 1" << endl;
    }
    else if(S == 1000000000000000000)
    {
        cout << "0 0 1000000000 0 0 1000000000" << endl;
    }
    else
    {
        S += 1000000000;
        temp = S % 1000000000;
        S -= temp;
        cout << "0 1000000000 1 0 " << S / 1000000000 << " " << temp << endl; 
    }
    //system("pause");
    return 0;
}