#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include <utility>
#include<stdio.h>
#include<climits>
#include <vector>

using namespace std;

int main(void){
    int n;
    vector<int> v;
    int i,j;
    v.push_back(2);
    for(j = 3;j < 300000;j++){
        for(i = 0;i < v.size();i++){
            if(j%v[i] == 0) break;
            if(v[i]*v[i] > j){
                v.push_back(j);
                break;
            }
        }
    }
    while(1){
        cin >> n;
        if(!n) break;
        j = 0;
        for(i = 0;i < v.size();i++){
            if(v[i] > 2*n) break;
            if(n < v[i]) j++;
        }
        cout << j << endl;
    }
}