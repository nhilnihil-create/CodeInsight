#include<bits/stdc++.h>
using namespace std;

int main(){
        long long x, money = 100, i;
        cin >> x;

        for(i = 0; money < x; ++i){
                money += money / 100;                                                                                                
        }

        cout << i << endl;
        return 0;
}
