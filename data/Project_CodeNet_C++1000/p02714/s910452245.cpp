#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main(void){
    int n, r, g, b, x;
    string color;
    cin >> n;
    cin >> color;
    r = g = b = x = 0;
    
    for(int i=0; i<n; i++){
        if(color[i] == 'R') r++;
        else if(color[i] == 'G') g++;
        else b++;
        for(int j=i+1, k=i+2; k<n; j++, k+=2)
            if(color[i]!=color[j] && color[j]!=color[k] && color[k]!=color[i]) x++;
    }
    cout << (int64_t)r*g*b - x << '\n';
    return 0;
}