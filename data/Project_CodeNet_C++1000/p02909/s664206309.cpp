#include <bits/stdc++.h>

using namespace std;

int main() {

    string arr[3] = {"Sunny","Cloudy","Rainy"};
    string s;
    cin>>s;
    int x = find(arr,arr+3,s)-arr;
    cout<<arr[(x+1)%3]<<endl;



    return 0;
}
