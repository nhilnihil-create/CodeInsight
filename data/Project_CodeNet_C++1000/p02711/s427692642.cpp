#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < 3;i++)
    {
        if(n%10==7)
        {
            cout << "Yes" << endl;
            break;
        }else
        {
            n /= 10;
            if(i==2)
            {
                cout << "No";
            }
        }
    }
    return 0;
}