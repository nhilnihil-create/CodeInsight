#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;





int main() {
    int n;
    cin>>n;
    int s = 1000;
    if(s < n){
        while(s < n){
            s += 1000;
        }
    }
    cout<<s-n;
    return 0;
}