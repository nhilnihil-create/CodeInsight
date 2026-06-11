#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    //N個の要素数の配列をソートして小さい順にK個足す

    int num, kosu;
    vector <int> price;
    cin >> num >> kosu;

    //cout << num << "  " << kosu << "\n";
    int tmp;
    for(int i =0; i < num; i++)
    {
        cin >> tmp;
        price.push_back(tmp);
    }

    sort(price.begin(), price.end());

    int sum_price =0;

    for(int j =0; j< kosu; j++)
    {
        sum_price += price[j];
    }

  	cout << sum_price;
  
    return 0;
}

