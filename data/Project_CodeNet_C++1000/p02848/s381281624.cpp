#include<bits/stdc++.h>
using namespace std;

bool cmp(const char& aa, const char& bb){
    if(tolower(aa) == tolower(bb))
        return (aa < bb);
    else
        return (tolower(aa) < tolower(bb));
}

void solve(){
    string aa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i= 0 ; i<s.size();i++){
        if((s[i]+n)>'Z'){
                int p = int(s[i]+n-1-'Z');
            s[i] = aa[p];
        }
        else{
            s[i] = s[i] + n;
        }
    }
    cout << s << endl;

}
int main(){
    //int t; cin >> t; while(t--)
    solve();

    return 0;
}



