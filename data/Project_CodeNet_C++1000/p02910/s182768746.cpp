#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    string S;
    cin >> S;
    bool flag = true;
    for(int i=0; i<S.length(); ++i){
        if(i%2==0){
            if(S[i]!='R'&&S[i]!='U'&&S[i]!='D') flag = false;
        }
        else{
            if(S[i]!='L'&&S[i]!='U'&&S[i]!='D') flag = false;
        }
    }

    cout << (flag==true ? "Yes": "No") << endl;
    return 0;
}
