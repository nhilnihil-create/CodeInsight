#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b; 
    cin >> a >> b;
    if(a<=b+b)
    {
        cout << "0" << endl;
        return 0;
    }
    cout << a-b-b << endl;

 
}
