#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <numeric>
#include<bits/stdc++.h>

using namespace std;


int main(){
 
int a,b;
string strans = "";
cin>>a>>b;

if(a <= b){
    string stra;
    stra = to_string(a);
    for(int i = 0; i < b; i++){
        strans += stra;}
        cout<<strans<<endl;
    }else{
    string strb;
    strb = to_string(b);
    for(int i = 0; i < a; i++){
        strans += strb;}
        cout<<strans<<endl;
    }
}
