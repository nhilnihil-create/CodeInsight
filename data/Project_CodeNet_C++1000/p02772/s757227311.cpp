#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void){
    int n;
    cin >> n;
    int count1 = 0;
    int count2 = 0;
    rep(i,n){
        int k;
        cin >> k;
        if(k%2 == 0){
            count1++;
            if(k%3 == 0 || k%5 == 0){
                count2++;
            }
        } 
    }
    if(count1 == count2){
        cout << "APPROVED" << endl;
    }else{
        cout << "DENIED" << endl;
    }
}