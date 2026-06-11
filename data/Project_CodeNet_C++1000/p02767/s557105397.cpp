#include <bits/stdc++.h>
#include <map>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int>x(n) ;
    for(int i=0;i<n;i++)cin >> x[i];
    
    int hp = 12345678;
    for(int p=1;p<=100;p++){
        int hp_v = 0;
        for(int j=0;j<n;j++){
            hp_v += pow(x[j]-p,2);
        }
        if(hp_v < hp) hp = hp_v; 
    }
    
    cout << hp;
    
    return 0;
}
