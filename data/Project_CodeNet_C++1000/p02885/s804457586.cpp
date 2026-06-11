#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if(b*2<a){
        cout << a-2*b << endl;
    }else{
        cout << "0\n";
    }
    return 0;
}
