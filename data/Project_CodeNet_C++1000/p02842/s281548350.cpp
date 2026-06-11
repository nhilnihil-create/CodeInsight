#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n;
    for (int i = 0; i < 50000;i++){
        x = i * 1.08;
        if(x==n){
            cout << i << endl;
            break;
        }
        if(i==49999){
            cout << ":(" << endl;
        }
    }
        return 0;
}