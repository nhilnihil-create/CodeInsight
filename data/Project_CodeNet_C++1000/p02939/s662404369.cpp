#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int stl = s.size();
    char last = '0';
    int cnt = 0;
    for(int i = 0;i < stl;i++){
        char S = s[i];
        if(S==last&&i<stl-1){
            S='0';
            i++;
        }
        if(S!=last) cnt++;
        last = S;
    }
    
    cout << cnt << endl;
    return 0;
}