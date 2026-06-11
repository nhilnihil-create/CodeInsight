#include <bits/stdc++.h>
using namespace std;

bool exist(vector<int> array,int y,int n){
    array.push_back(y);
    int i = 0;
    while(array.at(i) != y) i++;
    return i == n;
}
int main(){
    int x,n;
    cin >> x >> n;
    vector<int> array(n);
    for(int i=0;i<n;i++) cin >> array.at(i);
    if(exist(array,x,n)){
        cout << x << endl;
    }else{
        int idx = 0;
        while(true){
            idx++;
            if(exist(array,x-idx,n)){
                cout << x - idx << endl;
                break;
            }else if(exist(array,x+idx,n)){
                cout << x + idx << endl;
                break;
            }
        }
    }
}