#include <bits/stdc++.h>

using namespace std;

// Main function 
int main() 
{
    long int X;
    cin>>X;
    
    int a = 120, b = 120;
    
    for(int i = -118; i < 120; i++){
        for(int j = -119; j < 118; j++){
            if(i*i*i*i*i - j*j*j*j*j == X){
                a = i;
                b = j;
                break;
            }
        }
        if(a != 120 && b != 120){
            break;
        }
    }
    
    cout<<a<<" "<<b<<endl;
    return 0; 
} 