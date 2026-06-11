#include <bits/stdc++.h>

using namespace std;

int main(){

    string s,t;
    int i=0,j=0,cont=0;

    cin >> s >> t;

    int stam=s.size();
    

    for(i=0;i<stam;i++){
            if(s[i]!=t[i]){
                cont++;
            }
        
    }
    
    cout << cont << endl;
    

    return 0;
}