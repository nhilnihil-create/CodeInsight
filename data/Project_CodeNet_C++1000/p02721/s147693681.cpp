#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;

    vector<int> left(k), right(k);
    int count = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'o'){
            left[count] = i + 1;
            count += 1;
            i += c;
            if(count == k) break;
        }
    }
    count = k-1;
    for(int i=n-1; i>=0; i--){
        if(s[i] == 'o'){
            right[count] = i + 1;
            count -= 1;
            i -= c;
            if(count == -1) break;
        }
    }
    /*
    for(int i=0; i<k; i++) cout << left[i] << " ";
    cout << endl;
    for(int i=0; i<k; i++) cout << right[i] << " ";
    cout << endl;
    */
    for(int i=0; i<k; i++){
        if(left[i] == right[i]) cout << left[i] << endl;
    }
    return 0;
}