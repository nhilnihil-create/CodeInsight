#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int x[10];
    for (int i = 0; i < 5;i++)
    {
        cin >> x[i];
    }

    for (int i = 0; i < 5;i++)
    {
    if(x[i]==0)
    {
        cout << i + 1 << endl;
        break;
    }
    }
    return 0;
}