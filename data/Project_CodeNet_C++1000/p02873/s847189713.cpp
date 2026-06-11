#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    long long a[n+1] = {};
    long long count = 0; 
    for(int i = 0; i < n; i++){
        if(s[i] == '<'){
            count++;
            a[i+1] = count;
        }else{
            count = 0;
        }
    }
    count = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '>'){
            count++;
            a[i] = max(a[i],count);
        }else{
            count = 0;
        }
    }
    long long sum = 0;
    for(int i = 0; i <= n; i++){
        sum += a[i];
        //cout << a[i] << endl;
    }
    cout << sum << endl;
    return 0;
}