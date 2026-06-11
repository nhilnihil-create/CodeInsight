#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int a,b;cin >> a >> b;
    int t = 0;
    int cnt = 1;
    for(int i = 0;i < a;i++){
        int tmp = 0;
        cin >> tmp;
        if(t + tmp <= b)cnt++;
        t+=tmp;
    }
    cout << cnt << endl;
}