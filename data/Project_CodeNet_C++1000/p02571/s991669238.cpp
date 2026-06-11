#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string s,t;cin>>s>>t;
    int mka = t.length();
    if(s == t){
    	cout<<"0";
        return 0;
    }
    for(int i = 0;i<=s.length()-t.length();i++){
        int kasanari = 0;
        for(int j = 0;j<t.length();j++){
           if(s[i+j]!=t[j])kasanari += 1;
        }
        mka = min(mka,kasanari);
    }
    cout<<mka;
    return 0;
}