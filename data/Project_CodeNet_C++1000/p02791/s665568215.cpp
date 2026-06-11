#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i=0;i<n;i++) cin >> array.at(i);
    int left = n+1,c=0;
    for(int i=0;i<n;i++){
        if(left > array.at(i)) {
            left = array.at(i);
            c++;
        }
    }
    cout << c << endl;
}