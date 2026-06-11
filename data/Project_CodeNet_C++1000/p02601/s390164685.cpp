#include <bits/stdc++.h>
#include <iostream> 
#include <stdio.h>
#define MAX 20000005
typedef long long ll; 
using namespace std; 
int main () 
{

    int a , b, c; 
    int k; 
    cin >> a >> b >> c; 
    cin >> k ;
    int total = 0;  

    while (b<=a) 
    {
        b = b*2; 
        total ++; 
    }
    while (c<=b) 
    {
        c = c*2; 
        total++; 
    }
    if (total <= k) {
        cout << "Yes" << endl; 
        
    }else 
        {
            cout << "No" << endl; 
        }

    return 0; 
}
