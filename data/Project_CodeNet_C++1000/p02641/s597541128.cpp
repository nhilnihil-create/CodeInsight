#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,s,temp;
    cin >> a >> s;
    vector <int> b;
    for(int i=0;i<s;i++){
        cin >> temp;
        b.push_back(temp-a);
    }
    sort(b.begin(),b.end());
    //
    temp = 0;
    while(temp < s && b[temp]!=0) temp++;

    if (temp >=s) {cout << a;return 0;}

    int i=0,j=0;
    
    while(temp-i>=0 && temp+j<s){
        
        if(b[temp-i]!=-1*i) {
            cout << a-i;
            return 0;
        }
        else if(b[temp+j]!=j) {
            cout << a+j;
            return 0;
        }
        i++;j++;
        
    }
    if(temp-i>=0 && b[temp-i]!=-1*i) cout << a-i;
    else if(temp-i<0) cout << a-i;
    else if(temp+j>=s) cout << a+j;
    else cout << a+j;
    return 0;
}
