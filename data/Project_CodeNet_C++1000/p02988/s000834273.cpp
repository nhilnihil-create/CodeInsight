#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>

using namespace std;

int main(){
    int n ;
    int cnt = 0;
    cin >> n;
    vector<int> v (n,0);
    for(int i ;i < n ;i++){
        cin >> v.at(i);
    }
    for (int i = 1; i< n-1 ;i++){
        if (((v.at(i) < v.at(i-1))&&(v.at(i) > v.at(i+1))) || ((v.at(i) > v.at(i-1))&&(v.at(i) < v.at(i+1)))){
            cnt += 1;
        }
    }
    cout << cnt << endl;
} 
