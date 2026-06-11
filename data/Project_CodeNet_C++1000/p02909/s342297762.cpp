#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<string> v;
    v.push_back("Sunny");
    v.push_back("Cloudy");
    v.push_back("Rainy");

    string input;
    cin >> input;
    int index;
    if(input == "Sunny"){
        index = 0;
    }else if(input == "Sunny"){
        index = 1;
    }else if(input == "Rainy"){
        index = 2;
    }

    int next = index + 1;
    cout << v[next%3];

}
