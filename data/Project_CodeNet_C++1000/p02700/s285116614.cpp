#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int healthTak, strengthTak, healthAok, strengthAok;
    cin >> healthTak >> strengthTak >> healthAok >> strengthAok;
    int cntr = 0;
    while(true){
        if(cntr % 2 == 0){
            if(healthTak <= 0)
                return cout << "No", 0;
            healthAok -= strengthTak;
        }
        else {
            if(healthAok <= 0)
                return cout << "Yes", 0;
            healthTak -= strengthAok;
        }
        cntr++;
    }
    return 0;
}