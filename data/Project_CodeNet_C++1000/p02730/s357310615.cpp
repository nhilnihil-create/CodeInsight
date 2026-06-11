#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s;
    cin >> s;
    int n = s.size();
    int n2 = n/2;
    bool suc = true;
    for(int i=0; i<n; i++) if(s[i]!=s[n-1-i]){suc=false; break;}
    for(int i=0; i<n2; i++) if(s[i]!=s[n2-1-i]){suc=false; break;}
    for(int i=0; i<n2; i++) if(s[n2+1+i]!=s[n-1-i]){suc=false; break;}
    if(suc) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}