#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n;
    cin>>n;
    int m = 0;
    for(int i = 1; i<n + 1; i++){
        if(i < 10){
            m++;
        }else if(i >= 100 && i < 1000){
            m++;
        }else if(i >= 10000 && i < 100000){
            m++;
        }
    }cout<<m<<endl;
}
