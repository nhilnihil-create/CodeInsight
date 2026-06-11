#include <bits/stdc++.h>
using namespace std;
int main(){
    long n; cin >> n;
    long cnt = 0;
    string s; cin >> s;
    vector<int> v(3);
    for(int i=0;i<1000;i++){
        v[0] = i/100; v[1] = (i%100)/10; v[2] = i%10;
        long a = 0;
        for(int j=0;j<n;j++){
            if(v[a] == (int)(s[j]-'0'))a++;
            if(a == 3){
                cnt++;
                break;
            }
        }
        a = 0;
    }
    cout << cnt << endl;
}    