#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
typedef long long ll;
using namespace std;
 
 
int main(){
    string s; cin >> s;
    int sl=s.length(); bool ans=false;
    if(sl%2==1) cout << "No" << endl;
    else{
    for(int i=0; i<sl; i=i+2){
        if(s[i]!='h' || s[i+1]!='i'){
            ans=true;
            break;
        }
    }
    if(ans) cout << "No" << endl;
    else cout << "Yes" << endl;
    }
return 0;
}