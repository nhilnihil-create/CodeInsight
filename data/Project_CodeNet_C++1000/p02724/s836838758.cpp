#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n,sum,hp=0;
    cin >> n;
    sum = n/500;
    hp = sum*1000;
    n-= sum*500;
    sum = n/5;
    hp += sum*5;
    cout << hp;
}