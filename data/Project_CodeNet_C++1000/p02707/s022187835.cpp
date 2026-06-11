#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> array(n,0);
    for(int i=0;i<n-1;i++){
        int num;
        cin >> num;
        array.at(num-1)++;
    }

    for(int i=0;i<n;i++) cout << array.at(i) << endl; 
}