#include <bits/stdc++.h>
using namespace std;

int main(){
        string s;
        cin>>s;
        
        cout<< (s=="RRR"? 3:(s=="RRS" || s=="SRR" ? 2:(s=="SSS" ? 0:1)));
        cout<<"\n";
        return 0;

    }
