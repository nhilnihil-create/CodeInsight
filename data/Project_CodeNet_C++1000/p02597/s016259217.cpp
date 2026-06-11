//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n,i,j;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt3 = 0;
    string s;
    cin >> n;
    cin >> s;
    
    for(i = 0;i<n;i++){
        if(s[i] == 'W') cnt0++;
        else if(s[i] == 'R') cnt1++; 
    }
    i = 0;
    j = n-1;
    while(i<j){
        if(s[i] == 'W' && s[j] == 'R'){
            swap(s[i],s[j]);
            i++;
            j--;
            cnt3++;
        }else if(s[i] == 'R' && s[j] == 'W'){
            i++;
            j--;
        }else if(s[i] == 'W' && s[j] == 'W') j--;
        else i++;
    }
      cout << min({cnt1,cnt0,cnt3}) << endl;
    return 0;
}

