#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n;
    vector <int> data(200001,0);
    cin >> n;
    int x;
    for(int i=0;i<n-1;i++){
        cin >>x;
        data.at(x-1)+=1;
    }
    for(int i=0;i<n;i++){
        cout << data.at(i) <<endl;
    }
}
