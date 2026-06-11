#include<bits/stdc++.h>
using namespace std;


int main(){
    long long n; cin >> n;
    long long money=1000; long long stock=0;
    int before; cin>>before;
    int after;
    for (int i=1; i<n; i++){
        cin >> after;
        if(after>before){
            stock = money/before;
            money = money%before;
            money += stock * after;
            stock = 0;
        }
        
        before = after;
    }
    cout << money << endl;
}