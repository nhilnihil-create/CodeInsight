#include<iostream>
using namespace std;

int main()
{
    int n, m;
    bool t = true;
    cin >> n;
    m = n;
    while(cin >> n){
        if(m >= n){ t = false; break; }else{ m = n; }
    };
    if(t){ cout << "Yes"; }else{ cout << "No"; }
    cout << endl;

    return 0;
}