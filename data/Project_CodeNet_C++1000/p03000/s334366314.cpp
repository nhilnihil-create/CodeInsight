#include<bits/stdc++.h> 
using namespace std; 
  
int main() 
{
    int n, x, y;
    cin >> n >> x;
    int pos = 0;
    int sol = 1;
    for(int i = 1; i <= n; i++) {
        cin >> y;
        pos += y;
        if(pos <= x) {
            sol++;
        }
    }
    cout << sol;
    return 0;
} 
