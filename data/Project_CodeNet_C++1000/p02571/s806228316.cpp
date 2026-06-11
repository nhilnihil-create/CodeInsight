#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
 
using namespace std;
 
int main() {
    string s,t;cin>>s>>t;
    int mka = 0;
    for(int i = 0;i<=s.length()-t.length();i++){
    	char tt[t.length()];
        int kasanari = 0;
        for(int j = 0;j<t.length();j++){
           tt[j] = s[i+j];
           if(tt[j] == t[j]) kasanari += 1;
        }
        mka = max(mka,kasanari);
    }
    cout<<t.length()-mka;
    return 0;
}