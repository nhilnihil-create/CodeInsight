#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,d,a,b;
    cin >> n >> d;
    a = n/(d*2+1);
    b = n%(d*2+1);
    if (b==0){
        cout << a << endl;
    }else{
        cout << a+1 << endl;
    }


}