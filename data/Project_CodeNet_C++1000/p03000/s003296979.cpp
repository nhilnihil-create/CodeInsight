#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>
#include <map>
#include <utility>

using namespace std;

int main(){

    int n;
    cin >> n;
    int x;
    cin >> x;

    int l[n];

    int all = 0;
    int cnt;

    for(int i = 0; i < n; i++){
        cin >> l[i];
        all+=l[i];
        if(all <= x){
            cnt++;
        }
    }
    
    cout << cnt + 1 << endl;
}