/// You just can't beat the person who never gives up
/// ICPC next year

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+5 ;

string str ;
int main(){
    cin >> str ;
    if(str.size()%2) return cout << "No",0;
    for(int i=0;i<str.size();i+=2){
        if(str[i]=='h' && str[i+1]=='i') continue ;
        return cout << "No",0;
    }
    return cout << "Yes",0;
    return 0;
}
