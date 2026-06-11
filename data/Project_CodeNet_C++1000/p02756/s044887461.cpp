#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int q; cin >> q;
    int t;
    int rev=0;
    for(int i=0; i<q; i++){
        int t; cin >> t;
        if(t==1){   
            rev++;
        }else if(t==2){
            int f; cin >> f;
            string c; cin >> c;
            if((f==1 && rev%2==0) || (f==2 && rev%2==1)){
                s.insert(0, c);
            }else if((f==2 && rev%2==0) || (f==1 && rev%2==1)){
                s.append(c);
            }
        }
    }
    if(rev%2==1){
        reverse(s.begin(), s.end());
    }
    cout << s << endl;
    return 0;
}