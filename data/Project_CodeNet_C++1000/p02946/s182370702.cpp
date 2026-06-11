#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int k,x;
    cin >> k >> x;
    for (int i = 0; i < 2*k-1; i++)
    {
        cout << x-k+i+1 << ' ';
    }
    cout << endl;
}