#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin>>n;
    int digit = n%10;
    if(digit == 3){
        cout<<"bon";
    } else if(digit == 0 || digit == 1 || digit == 6 || digit == 8){
    cout<<"pon";
    }else
    {
        cout<<"hon";
    }
    
    return 0;
}