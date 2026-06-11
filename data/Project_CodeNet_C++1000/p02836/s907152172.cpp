#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<numeric>

using namespace std;

int main(){
    string a, b;
    cin >> a;
    b = a;
    reverse(a.begin(),a.end());
    int ans = 0;

    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i]) ans++;
    }

    cout << ans / 2 << endl;

}