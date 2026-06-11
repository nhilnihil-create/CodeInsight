#include<bits/stdc++.h>
using namespace std;
int k, a, b;
int main()
{
    cin >> k;
    cin >> a >> b;
    if(a%k==0)
        cout << "OK" << endl;
    else{
        if((a/k+1)*k<=b)
            cout << "OK" <<endl;
        else
            cout << "NG" << endl;
    }
    return 0;
}
