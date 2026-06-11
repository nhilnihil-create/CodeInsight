#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long int a,c=1;
    cin >> a;
    string b;
    cin >> b;
    for (int i=0;i<b.size()-1;i++){
        
        if (b.at(i)!=b.at(i+1)){
            c++;
        }
        
    
        
    }
    cout << c << endl; 
}