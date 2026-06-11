#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int ss=s.size(),half=ss/2,count=0;
    for(int i=0;i<half;i++){
        if(s[i]!=s[ss-i-1]) count++;
    }
    cout << count << endl;
    return 0;

}
