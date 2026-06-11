#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
int n;
void dod(string s,char c){
    if(s.length()==n){
        cout << s << endl;
        return;
    }
    char d=c+1;
    int z=d-'a';
    rep(i,z){
      string ss=s;
      char x='a'+i;
      ss+=x;
      if(i!=z-1)dod(ss,c);
      else dod(ss,d);
    }
}

int main() {
    cin >> n;
    dod("",'a');

}