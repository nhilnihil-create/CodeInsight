#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,monster = 0,sum = 0;
    cin >> n;
    vector<int> city(n+1);
    vector<int> hero(n);
    for (int i = 0; i < n+1; i++){
        cin >> city.at(i);
        monster += city.at(i);
    }
    for (int i = 0; i < n; i++){
        cin >> hero.at(i);
    }
    for (int i = 0; i < n; i++){
        if(city.at(i) <= hero.at(i)){
        hero.at(i) -=city.at(i);
        city.at(i) = 0;
        }else{
            city.at(i) -= hero.at(i);
            hero.at(i) = 0;
            continue;
        }
        if(city.at(i+1) <= hero.at(i)){
        hero.at(i) -=city.at(i+1);
        city.at(i+1) = 0;
        }else{
            city.at(i+1) -= hero.at(i);
            hero.at(i) = 0;
            continue;
        }
    }
    for (int i = 0; i < n+1; i++){
        sum += city.at(i);
    }
    cout << monster - sum << endl;
}