#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 8;

int32_t main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
    string s;
    cin >> s;

    s = '!' + s;

    int n = s.size();

    for(int i = 1 ; i <= n ; i++){
        if(i%2 == 1){
            if(s[i] == 'L'){
                cout << "No\n";
                return 0;
            }
        }else{
            if(s[i] == 'R' ){
                cout << "No\n";
                return 0;
            }   
        }
    }

    cout << "Yes\n";
  return 0;
}


