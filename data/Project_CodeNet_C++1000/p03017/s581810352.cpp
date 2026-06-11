#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n,a,b,c,d;
    bool ok=true;
    bool ok_2 = false;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--;b--;c--;d--;
    if(c<d){
        for(int i=a; i<c-1; i++){
            if(s[i] == '#' && s[i+1] == '#') ok=false;
        }
        for(int i=b; i<d-1; i++){
            if(s[i] == '#' && s[i+1] == '#') ok=false;
        }
        ok_2 = true;
    }
    else{
        for(int i=a; i<c-1; i++){
            if(s[i] == '#' && s[i+1] == '#') ok=false;
        }
        for(int i=b; i<d-1; i++){
            if(s[i] == '#' && s[i+1] == '#') ok=false;
        }
        for(int i=b; i<=d; i++){
            if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') ok_2 =true;
        }
    }
    if(ok&&ok_2) cout << "Yes"<<endl;
    else cout << "No" << endl;
}