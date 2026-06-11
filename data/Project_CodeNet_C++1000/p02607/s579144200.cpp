#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int x,c=0;
    cin>>x;
    int arr[x];
    for(int i=0;i<x;i++){
        cin>>arr[i];
    }
    for(int i=0;i<x;i++){
        if(arr[i]%2!=0&&i%2==0){
            c++;
        }
    }
    cout<<c;
}