#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long int ll;

int main(){
    int n; cin >> n;
    n--;
    vector<int> v(500,0);
    for(int i=0;i<500;i+=2){
        v[i]=1;
    }
    for(int i=1;i<500;i+=4){
        v[i]=2;
    }
    for(int i=3;i<500;i+=8){
        v[i]=3;
    }
    for(int i=7;i<500;i+=16){
        v[i]=4;
    }
    for(int i=15;i<500;i+=32){
        v[i]=5;
    }
    for(int i=31;i<500;i+=64){
        v[i]=6;
    }
    for(int i=63;i<500;i+=128){
        v[i]=7;
    }
    for(int i=127;i<500;i+=256){
        v[i]=8;
    }
    for(int i=255;i<500;i+=512){
        v[i]=9;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << v[j] << " ";
        }
        cout << endl;
    }
}