#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n ;
    int cnt=0;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int awork;
        cin >> awork;
        a.push_back(awork);
    }
    for(int i=0;i<n;i++){
        if(a.at(i)%2!=0 && (i+1)%2 !=0){
            cnt++;
        }
    }
    cout << cnt;
    
}