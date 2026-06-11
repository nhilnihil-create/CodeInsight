#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a, b, c, d;
string s;

bool check(int start, int end){
    for(int i = start; i + 1 <= end; i++){
        if(s[i] == '#' && s[i+1] == '#'){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> a >> b >> c >> d >> s;
    a--, b--, c--, d--;
    
    if(!check(a, c) || !check(b, d)){
        cout << "No\n";
        return 0;
    }

    if(c > d){
        bool flat3 = false;
        for(int i = b; i <= d; i++){
            if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
                flat3 = true;
            }
        }
        if(!flat3){
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}